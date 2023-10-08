/*
 * exti.c
 *
 *  Created on: 2018-1-25
 *      Author: Administrator
 */

#include "exti.h"
#include "leds.h"
#include "key.h"


void EXTI1_Init(void)
{
	EALLOW;
	SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;    // GPIO input clock
	EDIS;

	EALLOW;
	//KEY�˿�����
	GpioCtrlRegs.GPAMUX1.bit.GPIO12=0;
	GpioCtrlRegs.GPADIR.bit.GPIO12=0;
	GpioCtrlRegs.GPAPUD.bit.GPIO12=0;
	//GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 0;        // �ⲿ�ж�1��XINT1����ϵͳʱ��SYSCLKOUTͬ��
	GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 2;        // �ⲿ�ж�1��XINT2�������޶�6����������
	GpioCtrlRegs.GPACTRL.bit.QUALPRD1 = 0xFF;   // ÿ���������ڵ�����Ϊ510*SYSCLKOUT

	GpioCtrlRegs.GPBMUX2.bit.GPIO48=0;
	GpioCtrlRegs.GPBDIR.bit.GPIO48=1;
	GpioCtrlRegs.GPBPUD.bit.GPIO48=0;
	GpioDataRegs.GPBCLEAR.bit.GPIO48=1;
	EDIS;

	EALLOW;
	GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL = 12;   // XINT1��GPIO12
	EDIS;

	EALLOW;	// �޸ı������ļĴ������޸�ǰӦ����EALLOW���
	PieVectTable.XINT1 = &EXTI1_IRQn;
	EDIS;   // EDIS����˼�ǲ������޸ı������ļĴ���

	PieCtrlRegs.PIEIER1.bit.INTx4 = 1;          // ʹ��PIE��1��INT4

	XIntruptRegs.XINT1CR.bit.POLARITY = 0;      // �½��ش����ж�
	XIntruptRegs.XINT1CR.bit.ENABLE= 1;        // ʹ��XINT1

	IER |= M_INT1;                              // ʹ��CPU�ж�1��INT1��
	EINT;                                       // ��ȫ���ж�
	ERTM;
}

interrupt void EXTI1_IRQn(void)
{
	Uint32 i;
	for(i=0;i<10000;i++);    //����������
	while(!KEY_H1);
	LED2_TOGGLE;
	PieCtrlRegs.PIEACK.bit.ACK1=1;
}


void EXTI2_Init(void)
{
	EALLOW;
	SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;    // GPIO input clock
	EDIS;

	EALLOW;
	//KEY�˿�����
	GpioCtrlRegs.GPAMUX1.bit.GPIO13=0;
	GpioCtrlRegs.GPADIR.bit.GPIO13=0;
	GpioCtrlRegs.GPAPUD.bit.GPIO13=0;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO13 = 2;        // �ⲿ�ж�2��XINT2�������޶�6����������
	GpioCtrlRegs.GPACTRL.bit.QUALPRD1 = 0xFF;   // ÿ���������ڵ�����Ϊ510*SYSCLKOUT


	GpioCtrlRegs.GPBMUX2.bit.GPIO48=0;
	GpioCtrlRegs.GPBDIR.bit.GPIO48=1;
	GpioCtrlRegs.GPBPUD.bit.GPIO48=0;
	GpioDataRegs.GPBCLEAR.bit.GPIO48=1;
	EDIS;

	EALLOW;
	GpioIntRegs.GPIOXINT2SEL.bit.GPIOSEL = 13;   // XINT2��GPIO13
	EDIS;

	EALLOW;	// �޸ı������ļĴ������޸�ǰӦ����EALLOW���
	PieVectTable.XINT2 = &EXTI2_IRQn;
	EDIS;   // EDIS����˼�ǲ������޸ı������ļĴ���

	PieCtrlRegs.PIEIER1.bit.INTx5 = 1;          // ʹ��PIE��1��INT5

	XIntruptRegs.XINT2CR.bit.POLARITY = 0;      // �½��ش����ж�
	XIntruptRegs.XINT2CR.bit.ENABLE = 1;        // ʹ��XINT2

	IER |= M_INT1;                              // ʹ��CPU�ж�1��INT1��
	EINT;                                       // ��ȫ���ж�
	ERTM;
}

interrupt void EXTI2_IRQn(void)
{
	Uint32 i;
	for(i=0;i<10000;i++);    //����������
	while(!KEY_H2);
	LED3_TOGGLE;
	PieCtrlRegs.PIEACK.bit.ACK1=1;
}

void EXTI3_Init(void)
{
	EALLOW;
	SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;    // GPIO input clock
	EDIS;

	EALLOW;
	//KEY�˿�����
	GpioCtrlRegs.GPAMUX1.bit.GPIO14=0;
	GpioCtrlRegs.GPADIR.bit.GPIO14=0;
	GpioCtrlRegs.GPAPUD.bit.GPIO14=0;
	//GpioCtrlRegs.GPAQSEL1.bit.GPIO14 = 0;        // �ⲿ�ж�3��XINT1����ϵͳʱ��SYSCLKOUTͬ��
	GpioCtrlRegs.GPAQSEL1.bit.GPIO14 = 2;        // �ⲿ�ж�2��XINT2�������޶�6����������
	GpioCtrlRegs.GPACTRL.bit.QUALPRD1 = 0xFF;   // ÿ���������ڵ�����Ϊ510*SYSCLKOUT

	GpioCtrlRegs.GPBMUX2.bit.GPIO48=0;
	GpioCtrlRegs.GPBDIR.bit.GPIO48=1;
	GpioCtrlRegs.GPBPUD.bit.GPIO48=0;
	GpioDataRegs.GPBCLEAR.bit.GPIO48=1;
	EDIS;

	EALLOW;
	GpioIntRegs.GPIOXINT3SEL.bit.GPIOSEL = 34;   // XINT3��GPIO34(XINT3Ҫ����GPIO32-GPIO63,���Դ˼��̵�·����,ʹ����������GPIO14��GPIO34ʵ�ֹ���)
	EDIS;

	EALLOW;	// �޸ı������ļĴ������޸�ǰӦ����EALLOW���
	PieVectTable.XINT3 = &EXTI3_IRQn;
	EDIS;   // EDIS����˼�ǲ������޸ı������ļĴ���

	PieCtrlRegs.PIEIER12.bit.INTx1 = 1;          // ʹ��PIE��12��INT1

	XIntruptRegs.XINT3CR.bit.POLARITY = 0;      // �½��ش����ж�
	XIntruptRegs.XINT3CR.bit.ENABLE= 1;        // ʹ��XINT3

	IER |= M_INT12;                              // ʹ��CPU�ж�1��INT12��
	EINT;                                       // ��ȫ���ж�
	ERTM;
}
interrupt void EXTI3_IRQn(void)
{
	Uint32 i;
	for(i=0;i<10000;i++);    //����������
	while(!KEY_H3);
	LED4_TOGGLE;
	PieCtrlRegs.PIEACK.bit.ACK1=1;
}
