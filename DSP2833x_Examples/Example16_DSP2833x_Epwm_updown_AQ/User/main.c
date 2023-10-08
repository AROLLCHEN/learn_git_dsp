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
#include "epwm.h"
#include "key.h"

/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/

Uint32 freq;
void main()
{
    char key=0;

    freq=10000;
	InitSysCtrl();

	InitPieCtrl();
	IER = 0x0000;
	IFR = 0x0000;
	InitPieVectTable();

	LED_Init();
	KEY_Init();
	TIM0_Init(150,200000);//200ms

    EPWM1_Init();


	while(1)
	{
	    key=KEY_Scan(0);
	    if(key==KEY1_PRESS)freq=freq+1;
	    if(key==KEY2_PRESS)freq=freq-1;
	    EPwm1_SetFreqPhase(freq,90);

	}
}

