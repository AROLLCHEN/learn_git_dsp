
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
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void main()
{
	InitSysCtrl();//系统时钟初始化，默认已开启F28335所有外设时钟

	LED_Init();
//	GpioDataRegs.GPCCLEAR.bit.GPIO68=1;

	while(1)
	{
//		GpioDataRegs.GPCTOGGLE.bit.GPIO68=1;//设置GPIO输出翻转信号
//		delay();
		LED1_TOGGLE;
		delay();
	}

}
