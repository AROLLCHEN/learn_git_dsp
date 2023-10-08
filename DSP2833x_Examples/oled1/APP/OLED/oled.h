#ifndef __OLED_H
#define __OLED_H			  	 
#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "delay.h"
#include "stdlib.h"	    
//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//OLED 驱动代码
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/4
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////
 

//OLED模式设置
//0: 4线串行模式  （模块的BS1，BS2均接GND）
//1: 并行8080模式 （模块的BS1，BS2均接VCC）
#define OLED_MODE 	0 

#define OLED_CS_H        (GpioDataRegs.GPASET.bit.GPIO5=1)
#define OLED_CS_L        (GpioDataRegs.GPACLEAR.bit.GPIO5=1)
#define OLED_RST_H        (GpioDataRegs.GPASET.bit.GPIO7=1)
#define OLED_RST_L        (GpioDataRegs.GPACLEAR.bit.GPIO7=1)
#define OLED_RS_H        (GpioDataRegs.GPASET.bit.GPIO6=1)
#define OLED_RS_L        (GpioDataRegs.GPACLEAR.bit.GPIO6=1)

#define OLED_SCLK_H        (GpioDataRegs.GPASET.bit.GPIO9=1)
#define OLED_SCLK_L        (GpioDataRegs.GPACLEAR.bit.GPIO9=1)
#define OLED_SDIN_H        (GpioDataRegs.GPASET.bit.GPIO8=1)
#define OLED_SDIN_L        (GpioDataRegs.GPACLEAR.bit.GPIO8=1)

#define OLED_CMD  	0		//写命令
#define OLED_DATA 	1		//写数据
//OLED控制用函数
void OLED_WR_Byte(u8 dat,u8 cmd);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Refresh_Gram(void);		   
							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode);
void OLED_ShowNum(u8 x,u8 y,Uint32 num,u8 len,u8 size);
void OLED_ShowString(u8 x,u8 y,const u8 *p,u8 size);
void OLED_ShowDecimals(Uint16 x,Uint16 y,const u8 *p,u8 size,int get);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode);
void OLED_ShowGBK(u8 x, u8 y,  u8 num, u8 size,u8 mode);
void OLED_ShowBMP(u8 x, u8 y, u8 px, u8 py, u8 index, u8 mode);

#endif  
	 



