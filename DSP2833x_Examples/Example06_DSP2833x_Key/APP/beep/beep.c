/*
 * beep.c
 *
 *  Created on: 2023��9��14��
 *      Author: CHENJIE
 */
#include "beep.h"

/*******************************************************************************
* �� �� ��         : BEEP_Init
* ��������		   : ��������ʼ��
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void BEEP_Init(void)
{
	EALLOW;
	SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;// ����GPIOʱ��
	//BEEP�˿�����
	GpioCtrlRegs.GPAMUX1.bit.GPIO6=0;
	GpioCtrlRegs.GPADIR.bit.GPIO6=1;
	GpioCtrlRegs.GPAPUD.bit.GPIO6=0;
	GpioDataRegs.GPACLEAR.bit.GPIO6=1;

	EDIS;



}

