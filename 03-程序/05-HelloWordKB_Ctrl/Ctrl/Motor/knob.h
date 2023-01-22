#ifndef HELLOWORD_DYNAMIC_FW_KNOB_H
#define HELLOWORD_DYNAMIC_FW_KNOB_H

#include "motor.h"


class KnobSimulator
{
public:
    KnobSimulator() = default;;

    enum Mode_t
    {
        MODE_DISABLE = 0,
        MODE_INERTIA,       // 惯性
        MODE_ENCODER,       // 编码器
        MODE_SPRING,        // 弹簧
        MODE_DAMPED,        // 阻尼
        MODE_PROGRAM,       // 程序控制
        MODE_SPIN           // 旋转
    };

    void Init(Motor* _motor);
    void Tick();
    void ApplyZeroPos();
    void SetEnable(bool _en);
    void SetMode(Mode_t _mode);
    Mode_t GetMode();
    void SetLimitPos(float _min, float _max);
    float GetPosition();
    float GetLapPosition();
    float GetVelocity();
    int GetEncoderModePos();
    void SetMotorTarget(float target);


private:
    Motor* motor{};
    Mode_t mode = MODE_DISABLE;
    float limitPositionMin = -2.356194f;
    float limitPositionMax = 2.356194f;
    int encoderDivides = 15;
    int encoderPosition = 0;

    float lastAngle{};
    float lastVelocity{};
};

#endif //HELLOWORD_DYNAMIC_FW_KNOB_H
