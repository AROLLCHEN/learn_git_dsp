/*
 * main.c
 *
 *  Created on: 2018-3-21
 *      Author: Administrator
 */


#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#include "leds.h"
#include "time.h"
#include "uart.h"
#include "stdio.h"
#include "lcd1602.h"


/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void main()
{
	int i=0;
	unsigned char s[]="123456";

	InitSysCtrl();
	InitPieCtrl();
	IER = 0x0000;
	IFR = 0x0000;
	InitPieVectTable();

	LED_Init();
	TIM0_Init(150,200000);//200ms
	UARTa_Init(4800);
	LCD1602_Init();
//	LCD1602_DispString(1," Hello ok ");
//	LCD1602_DispStringEx(2,1,"www.prechin.cn");
	 LCD1602_WriteCmd(0xc2);
	 DispStr(s);
//	 LCD1602_WriteData('s');
//	 LCD1602_WriteData('5');
//	 LCD1602_WriteCmd(0xc6);
//	 LCD1602_WriteData('6');
//	 LCD1602_WriteData('7');
	while(1)
	{

	}
}

