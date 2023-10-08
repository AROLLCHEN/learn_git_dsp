/*
 * main.c
 *
 *  Created on: 2023��9��14��
 *      Author: CHENJIE
 */
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "beep.h"
#include "leds.h"


/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void main()
{
	int i=0;
	InitSysCtrl();//ϵͳʱ�ӳ�ʼ����Ĭ���ѿ���F28335��������ʱ��

	LED_Init();
	BEEP_Init();

	while(1)
	{
		i++;
		if(i==1000)
		{
			i=0;
			LED1_TOGGLE;
		}
		BEEP_TOGGLE;
		DELAY_US(100);
	}

}
