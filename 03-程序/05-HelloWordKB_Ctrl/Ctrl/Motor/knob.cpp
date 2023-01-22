#include <cmath>
#include <cstdio>
#include "knob.h"


void KnobSimulator::Init(Motor* _motor)
{
    motor = _motor;
    motor->config.controlMode = Motor::ControlMode_t::TORQUE;
    motor->config.voltageLimit = 1.5;
    motor->config.velocityLimit = 100;
    motor->config.pidVelocity.p = 0.1;
    motor->config.pidVelocity.i = 0.0;
    motor->config.pidVelocity.d = 0.0;
    motor->config.pidAngle.p = 80;
    motor->config.pidAngle.i = 0;
    motor->config.pidAngle.d = 0.7;

    // When motor calibrated, we can replace Init with something like:
#if (1)
    motor->Init(2.082379, EncoderBase::CCW);
#else
    if (motor->Init())
    {
        printf("ZeroElectricAngleOffset: %f | Encoder direction: %s\n", motor->zeroElectricAngleOffset,
               motor->encoder->countDirection == EncoderBase::CW ? "CW" : "CCW");
        motor->target = 0;
        motor->SetEnable(false);
    } else
        printf("Error[%d]\n", motor->error);
#endif
}


void KnobSimulator::SetMode(KnobSimulator::Mode_t _mode)
{
    mode = _mode;

    lastAngle = GetPosition();
    lastVelocity = GetVelocity();

    switch (mode)
    {
        case MODE_DISABLE:
            motor->SetEnable(false);
            break;
        case MODE_INERTIA:
        {
            motor->SetEnable(true);
            motor->SetTorqueLimit(0.5);
            motor->config.controlMode = Motor::VELOCITY;
            motor->config.pidVelocity.p = 0.1;
            motor->config.pidVelocity.i = 0.0;
            motor->config.pidVelocity.d = 0.0;
            motor->config.pidAngle.p = 20;
            motor->config.pidAngle.i = 0;
            motor->config.pidAngle.d = 0.7;
            motor->target = 0;
        }
            break;
        case MODE_ENCODER:
        {
            motor->SetEnable(true);
            motor->SetTorqueLimit(0.6);
            motor->config.controlMode = Motor::ControlMode_t::ANGLE;
            motor->config.pidVelocity.p = 0.1;
            motor->config.pidVelocity.i = 0.0;
            motor->config.pidVelocity.d = 0.0;
            motor->config.pidAngle.p = 100;
            motor->config.pidAngle.i = 0;
            motor->config.pidAngle.d = 3.5;
            motor->target = 0.0f;
            lastAngle = 0.0f;
        }
            break;
        case MODE_SPRING:
        {
            motor->SetEnable(true);
            motor->SetTorqueLimit(1.5);
            motor->config.controlMode = Motor::ControlMode_t::ANGLE;
            motor->config.pidVelocity.p = 0.1;
            motor->config.pidVelocity.i = 0.0;
            motor->config.pidVelocity.d = 0.0;
            motor->config.pidAngle.p = 100;
            motor->config.pidAngle.i = 0;
            motor->config.pidAngle.d = 3.5;
            motor->target = 0.0f;
        }
            break;
        case MODE_DAMPED:
        {
            motor->SetEnable(true);
            motor->SetTorqueLimit(1.5);
            motor->config.controlMode = Motor::ControlMode_t::VELOCITY;
            motor->config.pidVelocity.p = 0.1;
            motor->config.pidVelocity.i = 0.0;
            motor->config.pidVelocity.d = 0.0;
            motor->target = 0;
        }
            break;
        case MODE_SPIN:
        {
            motor->SetEnable(true);
            motor->SetTorqueLimit(1.5);
            motor->config.controlMode = Motor::ControlMode_t::VELOCITY;
            motor->config.pidVelocity.p = 0.3;
            motor->config.pidVelocity.i = 0.0;
            motor->config.pidVelocity.d = 0.0;
            motor->target = 10;
        }
            break;
        case MODE_PROGRAM:
        {
            motor->SetEnable(true);
            motor->SetTorqueLimit(1.0);
            motor->config.controlMode = Motor::ControlMode_t::ANGLE;
            motor->config.pidVelocity.p = 0.1;
            motor->config.pidVelocity.i = 0.0;
            motor->config.pidVelocity.d = 0.0;
            motor->config.pidAngle.p = 100;
            motor->config.pidAngle.i = 0;
            motor->config.pidAngle.d = 3.5;
            motor->target = 0.0f;
        }
            break;
    }
}


void KnobSimulator::Tick()
{
    switch (mode)
    {
        case MODE_INERTIA:
        {
            auto v = GetVelocity();
            if (v > 1 || v < -1)    // TODO
            {
                if (std::abs(v - lastVelocity) > 0.3)
                    motor->target = v;
            } else
            {
                motor->target = 0;
            }
            lastVelocity = v;
        }
            break;
        case MODE_ENCODER:
        {
            auto a = GetPosition();
            if (a - lastAngle > _PI / (float) encoderDivides)
            {
                motor->target += _2PI / (float) encoderDivides;
                lastAngle = motor->target;
                encoderPosition++;
            } else if (a - lastAngle < -_PI / (float) encoderDivides)
            {
                motor->target -= _2PI / (float) encoderDivides;
                lastAngle = motor->target;
                encoderPosition--;
            }
        }
            break;
        case MODE_DAMPED:
            if (limitPositionMax != 0 && limitPositionMin != 0)
            {
                auto a = GetPosition();
                if (a > limitPositionMax)
                {
                    motor->config.controlMode = Motor::ANGLE;
                    motor->target = limitPositionMax;
                } else if (a < limitPositionMin)
                {
                    motor->config.controlMode = Motor::ANGLE;
                    motor->target = limitPositionMin;
                } else
                {
                    motor->config.controlMode = Motor::VELOCITY;
                    motor->target = 0;
                }
            }
            break;
        case MODE_DISABLE:
        case MODE_SPRING:
        case MODE_SPIN:
            break;
    }

    motor->Tick();
}


void KnobSimulator::SetLimitPos(float _min, float _max)
{
    limitPositionMin = _min;
    limitPositionMax = _max;
}


void KnobSimulator::ApplyZeroPos()
{
    motor->ApplyZeroAngle();
    lastAngle = 0.0f;
}


float KnobSimulator::GetPosition()
{
    return motor->GetEstimateAngle();
}

float KnobSimulator::GetLapPosition()
{
    return Normalize(GetPosition());
}

float KnobSimulator::GetVelocity()
{
    return motor->GetEstimateVelocity();
}


int KnobSimulator::GetEncoderModePos()
{
    return std::lround(GetPosition() / (_2PI / (float) encoderDivides));
}


void KnobSimulator::SetEnable(bool _en)
{
    motor->SetEnable(_en);
}

KnobSimulator::Mode_t KnobSimulator::GetMode()
{
    return mode;
}

void KnobSimulator::SetMotorTarget(float target)
{
    motor->target = target;
}
