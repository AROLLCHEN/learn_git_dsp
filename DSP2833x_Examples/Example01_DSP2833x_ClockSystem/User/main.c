
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "leds.h"

void delay(void)
{
    Uint16 		i;
	Uint32      j;
	for(i=0;i<32;i++)
		for (j = 0; j < 100000; j++);
}



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
//	GpioDataRegs.GPCCLEAR.bit.GPIO68=1;

	while(1)
	{
//		GpioDataRegs.GPCTOGGLE.bit.GPIO68=1;//����GPIO�����ת�ź�
//		delay();
		LED1_TOGGLE;
		delay();
	}

}
