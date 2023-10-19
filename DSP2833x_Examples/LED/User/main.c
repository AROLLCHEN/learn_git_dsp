
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"

void main()
{
	InitSysCtrl();//ϵͳʱ�ӳ�ʼ����Ĭ���ѿ���F28335��������ʱ��

	InitGpio();//��ʼ������io��

	EALLOW;//д����
	GpioCtrlRegs.GPCMUX1.bit.GPIO68=0;//ѡ��Ϊgpio��
	GpioCtrlRegs.GPCDIR.bit.GPIO68=1;//���÷���Ϊ���
	EDIS;

	DINT;//��ֹcpu�����ж�

	InitPieCtrl();//��ʼ���жϿ��ƼĴ���

	IER = 0X0000;//��ֹcpu�ж�
	IFR = 0X0000;//���cpu�жϱ�־λ

	InitPieVectTable();//��ʼ��pie���ж�����

	EINT;//ʹ��cpu�ж�

	for(;;)
	{
	    GpioDataRegs.GPCCLEAR.bit.GPIO68=1;//����
	    DELAY_MS(200);
	    GpioDataRegs.GPCSET.bit.GPIO68=1;//����
	    DELAY_MS(200);
	}

}
