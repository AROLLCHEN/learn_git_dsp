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


/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void main()
{
	int i=0;
	unsigned char fx=0;

	InitSysCtrl();

	InitPieCtrl();
	IER = 0x0000;
	IFR = 0x0000;
	InitPieVectTable();

//	LED_Init();
	EPWM6_Init(500);

	while(1)
	{
		if(fx==0)
		{
			i++;
			if(i==300)
			{
				fx=1;
			}
		}
		else
		{
			i--;
			if(i==0)
			{
				fx=0;
			}
		}
		EPwm6A_SetCompare(i);  //iֵ������ȡ499����ΪARR���ֵ��499.
		EPwm6B_SetCompare(300-i);  //iֵ������ȡ499����ΪARR���ֵ��499.
		DELAY_US(10*1000);
	}
}
