/*
 * main.c
 *
 *  Created on: 2023��9��14��
 *      Author: CHENJIE
 */
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "leds.h"

/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void main()
{
	InitSysCtrl();//ϵͳʱ�ӳ�ʼ����Ĭ���ѿ���F28335��������ʱ��

	LED_Init();

	while(1)
	{
		GpioDataRegs.GPCTOGGLE.bit.GPIO68=1;//����GPIO�����ת�ź�
		DELAY_MS(200);
	}

}