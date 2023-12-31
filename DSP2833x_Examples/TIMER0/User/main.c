
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"

interrupt void ISRTimer0(void);

void main()
{
        InitSysCtrl();//系统时钟初始化，默认已开启F28335所有外设时钟

        InitGpio();//初始化所有io口

        InitCpuTimers();

//        EALLOW;//写保护
//        GpioCtrlRegs.GPCMUX1.bit.GPIO68=0;//选择为gpio口
//        GpioCtrlRegs.GPCDIR.bit.GPIO68=1;//设置方向为输出
//        EDIS;

        DINT;//禁止cpu所有中断

        InitPieCtrl();//初始化中断控制寄存器

        IER = 0X0000;//清除cpu中断
        IFR = 0X0000;//清除cpu中断标志位

        InitPieVectTable();//初始化pie的中断向量

        EALLOW;
        PieVectTable.TINT0 = &ISRTimer0;//定义定时器0中断
        EDIS;

        IER |=M_INT1;

        PieCtrlRegs.PIEIER1.bit.INTx7 = 1;

        EINT;//使能cpu中断
        ERTM;//使能全局调试功能

        ConfigCpuTimer(&CpuTimer0, 150, 1000000);//配置cpu定时器
        StartCpuTimer0();//启动定时器

        for(;;)
        {

        }


}

interrupt void ISRTimer0(void)
{


}



