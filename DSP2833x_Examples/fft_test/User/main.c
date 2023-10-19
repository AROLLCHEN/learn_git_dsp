/*
 * main.c
 *
 *  Created on: 2023��9��14��
 *      Author: CHENJIE
 */
#include "RFFT.h"
#include "epwm.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"


#define RAM_RUN     0
#define FLASH_RUN   1

#define RUN_TYPE    RAM_RUN

/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void main()
{
	/*��һ������ʼ��ϵͳ����:*/
	    InitSysCtrl();
	/*�ڶ�������ʼ��GPIO��*/
	    //InitGpio();
	/* ����������������ж� �ͳ�ʼ�� PIE ������:*/
	    //DINT;// ����CPU�ж�
	    InitPieCtrl();// ��ʼ�� PIE ���ƼĴ�����Ĭ��״̬��Ĭ��״̬��ȫ�� PIE �жϱ����úͱ�־λ�����
	    IER = 0x0000;// ���� CPU �жϺ�������� CPU �жϱ�־λ:
	    IFR = 0x0000;
	    InitPieVectTable();// ��ʼ�� PIE �ж�������
	    // �ж���ӳ�䣬ע���жϳ�����ڣ��û���������ӣ�
	/*������¼��28335����ѡ�ģ�*/
	#if RUN_TYPE==FLASH_RUN
	    MemCopy(&RamfuncsLoadStart,&RamfuncsLoadEnd,&RamfuncsRunStart);
	    InitFlash();
	#endif
	    RFFT_ADC_Init();

	    RFFT_ADC_Caculate();



}
