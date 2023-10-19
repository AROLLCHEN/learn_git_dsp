
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"

interrupt void ISRTimer0(void);

void main()
{
        InitSysCtrl();//ϵͳʱ�ӳ�ʼ����Ĭ���ѿ���F28335��������ʱ��

        InitGpio();//��ʼ������io��

        InitCpuTimers();

//        EALLOW;//д����
//        GpioCtrlRegs.GPCMUX1.bit.GPIO68=0;//ѡ��Ϊgpio��
//        GpioCtrlRegs.GPCDIR.bit.GPIO68=1;//���÷���Ϊ���
//        EDIS;

        DINT;//��ֹcpu�����ж�

        InitPieCtrl();//��ʼ���жϿ��ƼĴ���

        IER = 0X0000;//���cpu�ж�
        IFR = 0X0000;//���cpu�жϱ�־λ

        InitPieVectTable();//��ʼ��pie���ж�����

        EALLOW;
        PieVectTable.TINT0 = &ISRTimer0;//���嶨ʱ��0�ж�
        EDIS;

        IER |=M_INT1;

        PieCtrlRegs.PIEIER1.bit.INTx7 = 1;

        EINT;//ʹ��cpu�ж�
        ERTM;//ʹ��ȫ�ֵ��Թ���

        ConfigCpuTimer(&CpuTimer0, 150, 1000000);//����cpu��ʱ��
        StartCpuTimer0();//������ʱ��

        for(;;)
        {

        }


}

interrupt void ISRTimer0(void)
{


}



