/*
 * main.c
 *
 *  Created on: 2023年9月14日
 *      Author: CHENJIE
 */
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "leds.h"

/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void main()
{
	InitSysCtrl();//系统时钟初始化，默认已开启F28335所有外设时钟

	LED_Init();

	while(1)
	{
		GpioDataRegs.GPCTOGGLE.bit.GPIO68=1;//设置GPIO输出翻转信号
		DELAY_MS(200);
	}

}
