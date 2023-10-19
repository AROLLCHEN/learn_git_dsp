
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"

void main()
{
	InitSysCtrl();//系统时钟初始化，默认已开启F28335所有外设时钟

	InitGpio();//初始化所有io口

	EALLOW;//写保护
	GpioCtrlRegs.GPCMUX1.bit.GPIO68=0;//选择为gpio口
	GpioCtrlRegs.GPCDIR.bit.GPIO68=1;//设置方向为输出
	EDIS;

	DINT;//禁止cpu所有中断

	InitPieCtrl();//初始化中断控制寄存器

	IER = 0X0000;//禁止cpu中断
	IFR = 0X0000;//清除cpu中断标志位

	InitPieVectTable();//初始化pie的中断向量

	EINT;//使能cpu中断

	for(;;)
	{
	    GpioDataRegs.GPCCLEAR.bit.GPIO68=1;//拉低
	    DELAY_MS(200);
	    GpioDataRegs.GPCSET.bit.GPIO68=1;//拉高
	    DELAY_MS(200);
	}

}
