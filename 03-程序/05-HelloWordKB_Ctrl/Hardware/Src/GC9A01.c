
#include "GC9A01.h"
#include "cmsis_os.h"

#define USE_HORIZONTAL 2  //设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏

//-----------------LCD端口操作定义----------------
#define LCD_RES_Clr()  HAL_GPIO_WritePin(LCD_RST_GPIO_Port,LCD_RST_Pin, GPIO_PIN_RESET)//RES
#define LCD_RES_Set()  HAL_GPIO_WritePin(LCD_RST_GPIO_Port,LCD_RST_Pin, GPIO_PIN_SET)

#define LCD_DC_Clr()   HAL_GPIO_WritePin(LCD_RS_GPIO_Port,LCD_RS_Pin, GPIO_PIN_RESET)//DC
#define LCD_DC_Set()   HAL_GPIO_WritePin(LCD_RS_GPIO_Port,LCD_RS_Pin, GPIO_PIN_SET)

#define LCD_CS_Clr()   HAL_GPIO_WritePin(LCD_CS_GPIO_Port,LCD_CS_Pin, GPIO_PIN_RESET)//CS
#define LCD_CS_Set()   HAL_GPIO_WritePin(LCD_CS_GPIO_Port,LCD_CS_Pin, GPIO_PIN_SET)

#define delay_ms(ms)    osDelay(ms)

static void LCD_SPI_Write(uint8_t dat);//写入一个字节
static void LCD_WR_DATA(uint16_t dat);//写入两个字节
static void LCD_WR_REG(uint8_t dat);//写入一个指令


TIM_HandleTypeDef * hLCDBLTimer = &htim3;
SPI_HandleTypeDef *hLCDSPI = &hspi1;


void LCD_SetBrightness(uint8_t percent)
{
    if (percent > 100)
        percent = 100;

    __HAL_TIM_SetCompare(hLCDBLTimer, TIM_CHANNEL_2, (percent - 1));
    if (percent != 0)
        LCD_SetBacklightEnable(true);
}

void LCD_SetBacklightEnable(bool enable)
{
    if (enable)
        HAL_TIM_PWM_Start(hLCDBLTimer, TIM_CHANNEL_2);
    else
        HAL_TIM_PWM_Stop(hLCDBLTimer, TIM_CHANNEL_2);
}


/******************************************************************************
      函数说明：LCD串行数据写入函数
      入口数据：dat  要写入的串行数据
      返回值：  无
******************************************************************************/
void LCD_SPI_Write(uint8_t dat)
{
    LCD_CS_Clr();
    HAL_SPI_Transmit(hLCDSPI, &dat, 1, HAL_MAX_DELAY);
    LCD_CS_Set();
}

/******************************************************************************
      函数说明：LCD写入数据
      入口数据：dat 写入的数据
      返回值：  无
******************************************************************************/
void LCD_WR_DATA(uint16_t dat)
{
    uint8_t buff[2] = {dat>>8, dat};
    LCD_CS_Clr();
    HAL_SPI_Transmit(hLCDSPI, (uint8_t *)&buff, 2, HAL_MAX_DELAY);
    LCD_CS_Set();
}

/******************************************************************************
      函数说明：LCD写入命令
      入口数据：dat 写入的命令
      返回值：  无
******************************************************************************/
void LCD_WR_REG(uint8_t dat)
{
    LCD_DC_Clr();//写命令
    LCD_SPI_Write(dat);
    LCD_DC_Set();//写数据
}


/******************************************************************************
      函数说明：设置起始和结束地址
      入口数据：x1,x2 设置列的起始和结束地址
                y1,y2 设置行的起始和结束地址
      返回值：  无
******************************************************************************/
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
    LCD_WR_REG(0x2a);//列地址设置
    LCD_WR_DATA(x1);
    LCD_WR_DATA(x2);
    LCD_WR_REG(0x2b);//行地址设置
    LCD_WR_DATA(y1);
    LCD_WR_DATA(y2);
    LCD_WR_REG(0x2c);//储存器写
}

void LCD_Init(void)
{
    LCD_RES_Clr();//复位
    delay_ms(100);
    LCD_RES_Set();
    delay_ms(100);

    LCD_WR_REG(0xEF);
    LCD_WR_REG(0xEB);
    LCD_SPI_Write(0x14);

    LCD_WR_REG(0xFE);
    LCD_WR_REG(0xEF);

    LCD_WR_REG(0xEB);
    LCD_SPI_Write(0x14);

    LCD_WR_REG(0x84);
    LCD_SPI_Write(0x40);

    LCD_WR_REG(0x85);
    LCD_SPI_Write(0xFF);

    LCD_WR_REG(0x86);
    LCD_SPI_Write(0xFF);

    LCD_WR_REG(0x87);
    LCD_SPI_Write(0xFF);

    LCD_WR_REG(0x88);
    LCD_SPI_Write(0x0A);

    LCD_WR_REG(0x89);
    LCD_SPI_Write(0x21);

    LCD_WR_REG(0x8A);
    LCD_SPI_Write(0x00);

    LCD_WR_REG(0x8B);
    LCD_SPI_Write(0x80);

    LCD_WR_REG(0x8C);
    LCD_SPI_Write(0x01);

    LCD_WR_REG(0x8D);
    LCD_SPI_Write(0x01);

    LCD_WR_REG(0x8E);
    LCD_SPI_Write(0xFF);

    LCD_WR_REG(0x8F);
    LCD_SPI_Write(0xFF);


    LCD_WR_REG(0xB6);
    LCD_SPI_Write(0x00);
    LCD_SPI_Write(0x20);

    LCD_WR_REG(0x36);
    if(USE_HORIZONTAL==0)LCD_SPI_Write(0x08);
    else if(USE_HORIZONTAL==1)LCD_SPI_Write(0xC8);
    else if(USE_HORIZONTAL==2)LCD_SPI_Write(0x68);
    else LCD_SPI_Write(0xA8);

    LCD_WR_REG(0x3A);
    LCD_SPI_Write(0x05);


    LCD_WR_REG(0x90);
    LCD_SPI_Write(0x08);
    LCD_SPI_Write(0x08);
    LCD_SPI_Write(0x08);
    LCD_SPI_Write(0x08);

    LCD_WR_REG(0xBD);
    LCD_SPI_Write(0x06);

    LCD_WR_REG(0xBC);
    LCD_SPI_Write(0x00);

    LCD_WR_REG(0xFF);
    LCD_SPI_Write(0x60);
    LCD_SPI_Write(0x01);
    LCD_SPI_Write(0x04);

    LCD_WR_REG(0xC3);
    LCD_SPI_Write(0x13);
    LCD_WR_REG(0xC4);
    LCD_SPI_Write(0x13);

    LCD_WR_REG(0xC9);
    LCD_SPI_Write(0x22);

    LCD_WR_REG(0xBE);
    LCD_SPI_Write(0x11);

    LCD_WR_REG(0xE1);
    LCD_SPI_Write(0x10);
    LCD_SPI_Write(0x0E);

    LCD_WR_REG(0xDF);
    LCD_SPI_Write(0x21);
    LCD_SPI_Write(0x0c);
    LCD_SPI_Write(0x02);

    LCD_WR_REG(0xF0);
    LCD_SPI_Write(0x45);
    LCD_SPI_Write(0x09);
    LCD_SPI_Write(0x08);
    LCD_SPI_Write(0x08);
    LCD_SPI_Write(0x26);
    LCD_SPI_Write(0x2A);

    LCD_WR_REG(0xF1);
    LCD_SPI_Write(0x43);
    LCD_SPI_Write(0x70);
    LCD_SPI_Write(0x72);
    LCD_SPI_Write(0x36);
    LCD_SPI_Write(0x37);
    LCD_SPI_Write(0x6F);


    LCD_WR_REG(0xF2);
    LCD_SPI_Write(0x45);
    LCD_SPI_Write(0x09);
    LCD_SPI_Write(0x08);
    LCD_SPI_Write(0x08);
    LCD_SPI_Write(0x26);
    LCD_SPI_Write(0x2A);

    LCD_WR_REG(0xF3);
    LCD_SPI_Write(0x43);
    LCD_SPI_Write(0x70);
    LCD_SPI_Write(0x72);
    LCD_SPI_Write(0x36);
    LCD_SPI_Write(0x37);
    LCD_SPI_Write(0x6F);

    LCD_WR_REG(0xED);
    LCD_SPI_Write(0x1B);
    LCD_SPI_Write(0x0B);

    LCD_WR_REG(0xAE);
    LCD_SPI_Write(0x77);

    LCD_WR_REG(0xCD);
    LCD_SPI_Write(0x63);


    LCD_WR_REG(0x70);
    LCD_SPI_Write(0x07);
    LCD_SPI_Write(0x07);
    LCD_SPI_Write(0x04);
    LCD_SPI_Write(0x0E);
    LCD_SPI_Write(0x0F);
    LCD_SPI_Write(0x09);
    LCD_SPI_Write(0x07);
    LCD_SPI_Write(0x08);
    LCD_SPI_Write(0x03);

    LCD_WR_REG(0xE8);
    LCD_SPI_Write(0x34);

    LCD_WR_REG(0x62);
    LCD_SPI_Write(0x18);
    LCD_SPI_Write(0x0D);
    LCD_SPI_Write(0x71);
    LCD_SPI_Write(0xED);
    LCD_SPI_Write(0x70);
    LCD_SPI_Write(0x70);
    LCD_SPI_Write(0x18);
    LCD_SPI_Write(0x0F);
    LCD_SPI_Write(0x71);
    LCD_SPI_Write(0xEF);
    LCD_SPI_Write(0x70);
    LCD_SPI_Write(0x70);

    LCD_WR_REG(0x63);
    LCD_SPI_Write(0x18);
    LCD_SPI_Write(0x11);
    LCD_SPI_Write(0x71);
    LCD_SPI_Write(0xF1);
    LCD_SPI_Write(0x70);
    LCD_SPI_Write(0x70);
    LCD_SPI_Write(0x18);
    LCD_SPI_Write(0x13);
    LCD_SPI_Write(0x71);
    LCD_SPI_Write(0xF3);
    LCD_SPI_Write(0x70);
    LCD_SPI_Write(0x70);

    LCD_WR_REG(0x64);
    LCD_SPI_Write(0x28);
    LCD_SPI_Write(0x29);
    LCD_SPI_Write(0xF1);
    LCD_SPI_Write(0x01);
    LCD_SPI_Write(0xF1);
    LCD_SPI_Write(0x00);
    LCD_SPI_Write(0x07);

    LCD_WR_REG(0x66);
    LCD_SPI_Write(0x3C);
    LCD_SPI_Write(0x00);
    LCD_SPI_Write(0xCD);
    LCD_SPI_Write(0x67);
    LCD_SPI_Write(0x45);
    LCD_SPI_Write(0x45);
    LCD_SPI_Write(0x10);
    LCD_SPI_Write(0x00);
    LCD_SPI_Write(0x00);
    LCD_SPI_Write(0x00);

    LCD_WR_REG(0x67);
    LCD_SPI_Write(0x00);
    LCD_SPI_Write(0x3C);
    LCD_SPI_Write(0x00);
    LCD_SPI_Write(0x00);
    LCD_SPI_Write(0x00);
    LCD_SPI_Write(0x01);
    LCD_SPI_Write(0x54);
    LCD_SPI_Write(0x10);
    LCD_SPI_Write(0x32);
    LCD_SPI_Write(0x98);

    LCD_WR_REG(0x74);
    LCD_SPI_Write(0x10);
    LCD_SPI_Write(0x85);
    LCD_SPI_Write(0x80);
    LCD_SPI_Write(0x00);
    LCD_SPI_Write(0x00);
    LCD_SPI_Write(0x4E);
    LCD_SPI_Write(0x00);

    LCD_WR_REG(0x98);
    LCD_SPI_Write(0x3e);
    LCD_SPI_Write(0x07);

    LCD_WR_REG(0x35);
    LCD_WR_REG(0x21);

    LCD_WR_REG(0x11);
    delay_ms(120);
    LCD_WR_REG(0x29);
    delay_ms(20);
}


/******************************************************************************
      函数说明：在指定区域填充颜色
      入口数据：xsta,ysta   起始坐标
                xend,yend   终止坐标
								color       要填充的颜色
      返回值：  无
******************************************************************************/
void LCD_Fill(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend, uint16_t color)
{          
	uint16_t i,j; 
	LCD_Address_Set(xsta,ysta,xend-1,yend-1);//设置显示范围
	for(i=ysta;i<yend;i++)
	{													   	 	
		for(j=xsta;j<xend;j++)
		{
			LCD_WR_DATA(color);
		}
	} 					  	    
}

void LCD_Fill_Colors(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend, uint16_t *color)
{
    uint16_t i,j;
    LCD_Address_Set(xsta,ysta,xend,yend);//设置显示范围
    for(i=ysta;i<=yend;i++)
    {
        for(j=xsta;j<=xend;j++)
        {
            LCD_WR_DATA(*color++);
        }
    }
}

/******************************************************************************
      函数说明：在指定位置画点
      入口数据：x,y 画点坐标
                color 点的颜色
      返回值：  无
******************************************************************************/
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t color)
{
	LCD_Address_Set(x,y,x,y);//设置光标位置 
	LCD_WR_DATA(color);
} 
