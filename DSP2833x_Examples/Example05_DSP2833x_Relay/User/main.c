/*
 * main.c
 *
 *  Created on: 2018-3-21
 *      Author: Administrator
 */


#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#include "leds.h"
#include "relay.h"
#include "beep.h"


/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void main()
{
	int i=0;

	InitSysCtrl();

	LED_Init();
	Relay_Init();
	RELAY_ON;
	while(1)
	{
		i++;
		if(i%10==0)
		{
			RELAY_TOGGLE;
		}
		DELAY_MS(100);
	}
}
