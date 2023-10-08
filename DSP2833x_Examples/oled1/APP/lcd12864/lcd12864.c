/*
 * lcd12864.c
 *
 *  Created on: 2018-4-16
 *      Author: Administrator
 */



#include "lcd12864.h"
#include "charcode.h"

void LCD12864_GPIOInit(void)
{
	EALLOW;
	SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;// ����GPIOʱ��
	GpioCtrlRegs.GPAPUD.bit.GPIO0 = 0;    // ʹ��GPIO0 �����ڲ�����
	GpioCtrlRegs.GPAPUD.bit.GPIO1 = 0;   // ��ֹGPIO1 �����ڲ�����
	GpioCtrlRegs.GPBPUD.bit.GPIO48 = 0;
	GpioCtrlRegs.GPBPUD.bit.GPIO49 = 0;
	GpioCtrlRegs.GPBPUD.bit.GPIO60 = 0;

	GpioCtrlRegs.GPAMUX1.all = 0;   // ����GPIO0-GPIO15Ϊͨ��I/O��
	GpioCtrlRegs.GPBMUX2.bit.GPIO48 = 0;
	GpioCtrlRegs.GPBMUX2.bit.GPIO49 = 0;
	GpioCtrlRegs.GPBMUX2.bit.GPIO60 = 0;

	GpioCtrlRegs.GPADIR.all = 0x00FFF;// ����GPIO0-GPIO11Ϊ�������
	GpioCtrlRegs.GPBDIR.bit.GPIO48=1;
	GpioCtrlRegs.GPBDIR.bit.GPIO49=1;
	GpioCtrlRegs.GPBDIR.bit.GPIO60=1;

	// ÿ������ڿ����в�ͬ�������޶�
	// a) ������ϵͳʱ�� SYSCLKOUTͬ��
	// b) ���뱻ָ���Ĳ��������޶�
	// c) �����첽 (��������������Ч)
	GpioCtrlRegs.GPAQSEL1.all = 0x0000;    // GPIO0-GPIO15��ϵͳʱ��SYSCLKOUT ͬ��
	GpioCtrlRegs.GPBQSEL2.bit.GPIO48=0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO49=0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO60=0;

	EDIS;

	//�������LCD_RS��LCD_EN����
	LCD12864_CS_SETH;
	LCD12864_RS_SETL;
	LCD12864_RW_SETL;
	LCD12864_EN_SETL;
	LCD12864_RSET_SETH;
}

void LCD12864_WriteCmd(unsigned char cmd)
{
	LCD12864_CS_SETL;
	LCD12864_RW_SETH;
	LCD12864_RS_SETL;
	LCD12864_EN_SETL;
	DELAY_US(2);
	LCD12864_DATAPORT=cmd<<2;
	DELAY_US(2);
	LCD12864_EN_SETH;
}

void LCD12864_WriteData(unsigned char dat)
{
	LCD12864_CS_SETL;
	LCD12864_RW_SETH;
	LCD12864_RS_SETH;
	LCD12864_EN_SETL;
	DELAY_US(2);
	LCD12864_DATAPORT=dat<<2|0x0001;
	DELAY_US(2);
	LCD12864_EN_SETH;
}

void LCD12864_Init(void)
{
	unsigned int i;

	LCD12864_GPIOInit();
	DELAY_US(15000);//�ӳ�15ms
	LCD12864_RSET_SETL;
	for (i=0; i<1000; i++);
	LCD12864_CS_SETL;
	LCD12864_RSET_SETH;

	//----------------Star Initial Sequence-------//
	//------�����ʼ�����ã�����������Կ��ļ�����---//

	//--�����ʼ��--//
	LCD12864_WriteCmd(0xE2);  //reset
	for (i=0; i<1000; i++);	   //��ʱһ��

	//--����8�����0xA0�Σ����ң�����ѡ����������0xA1Ϊ������--//
	LCD12864_WriteCmd(0xA0);  //ADC select segment direction

	//--����15�����0xC8��ͨ(����)����ѡ��ѡ����0xC0Ϊ��������--//
	LCD12864_WriteCmd(0xC8);  //Common direction

	//--����9�����0xA6Ϊ��������Ϊ��ɫ������Ϊ��ɫ---//
	//--0xA7Ϊ��������Ϊ��ɫ������Ϊ��ɫ---//
	LCD12864_WriteCmd(0xA6);  //reverse display

	//--����10�����0xA4����������ʾ��0xA5����ȫ��--//
	LCD12864_WriteCmd(0xA4);  //normal display

	//--����11�����0xA3ƫѹΪ1/7,0xA2ƫѹΪ1/9--//
	LCD12864_WriteCmd(0xA2);  //bias set 1/9

	//--����19���������Ǹ�˫�ֽڵ����0xF800ѡ����ѹΪ4X;--//
	//--0xF801,ѡ����ѹΪ5X����ʵЧ�����--//
	LCD12864_WriteCmd(0xF8);  //Boost ratio set
	LCD12864_WriteCmd(0x01);  //x4

	//--����18���������Ǹ�˫�ֽ�������ֽ�Ϊ0X81�����ֽڿ���--//
	//--ѡ���0x00��0X3F���������ñ�����Աȶȡ�---/
	LCD12864_WriteCmd(0x81);  //V0 a set
	LCD12864_WriteCmd(0x23);

	//--����17�����ѡ����ڵ�����--//
	LCD12864_WriteCmd(0x25);  //Ra/Rb set

	//--����16�������Դ���á�--//
	LCD12864_WriteCmd(0x2F);
	for (i=0; i<1000; i++);

	//--����2�����������ʾ��ʼλ��--//
	LCD12864_WriteCmd(0x40);  //start line

	//--����1�����������ʾ--//
	LCD12864_WriteCmd(0xAF);  // display on
	for (i=0; i<1000; i++);
}

void LCD12864_ClearScreen(void)
{
	unsigned char i, j;

	for(i=0; i<8; i++)
	{
		//--����3���������Y������--//
		//--Y����64����һ������8λ��Ҳ������8������--//
		//����һ������ʹ�õ�Ҳ���Ǵ�0xB0��0x07,�͹���--//
		LCD12864_WriteCmd(0xB0+i);

		//--����4���������X����--//
		//--����Ķγ�ʼ��Ϊ0xA1ʱ��X�����0x10,0x04��0x18,0x04,һ��128λ--//
		//--����Ķγ�ʼ��Ϊ0xA0ʱ��X�����0x10,0x00��0x18,0x00,һ��128λ--//
		//--��д������֮��X����������ǻ��Զ���1�ģ����ǳ�ʼ��ʹ��0xA0����--//
		//--���ǵ�X�����0x10,0x00��ʼ---//
		LCD12864_WriteCmd(0x10);
		LCD12864_WriteCmd(0x00);

		//--X����128λ����һ��ˢ128�Σ�X������Զ���1���������ǲ�������������--//
		for(j=0; j<128; j++)
		{
			LCD12864_WriteData(0x00);  //������ñ���Ϊ��ɫʱ������ѡ��0XFF
		}
	}
}

unsigned char LCD12864_Write16CnCHAR(unsigned char x, unsigned char y, unsigned char *cn)
{
	unsigned char j, x1, x2, wordNum;

	//--Y������ֻ�ܴ�0��7��������ֱ�ӷ���--//
	if(y > 7)
	{
		return 0;
	}

	//--X������ֻ�ܴ�0��128��������ֱ�ӷ���--//
	if(x > 128)
	{
		return 0;
	}
	y += 0xB0;	   //��ȡY�����ֵ
	//--����Y����--//
	LCD12864_WriteCmd(y);
	while ( *cn != '\0')	 //��C�������ַ��������ԡ�\0����β
	{

		//--����Y����--//
		LCD12864_WriteCmd(y);

		x1 = (x >> 4) & 0x0F;   //����X����Ҫ��������ָߵ�4λ������������ȡ����4λ
		x2 = x & 0x0F;          //ȥ����λ
		//--����X����--//
		LCD12864_WriteCmd(0x10 + x1);   //��4λ
		LCD12864_WriteCmd(0x00 + x2);	//��4λ

		for (wordNum=0; wordNum<50; wordNum++)
		{
		    //--��ѯҪд�������ֿ��е�λ��--//
			if ((CN16CHAR[wordNum].Index[0] == *cn)
			     &&(CN16CHAR[wordNum].Index[1] == *(cn+1)))
			{
				for (j=0; j<32; j++) //дһ����
				{
					if (j == 16)	 //����16X16�õ�����Y���꣬�����ڵ���16ʱ���л�����
					{
						//--����Y����--//
						LCD12864_WriteCmd(y + 1);

						//--����X����--//
						LCD12864_WriteCmd(0x10 + x1);   //��4λ
						LCD12864_WriteCmd(0x00 + x2);	//��4λ
					}
					LCD12864_WriteData(CN16CHAR[wordNum].Msk[j]);
				}
				x += 16;
			}//if�鵽�ֽ���
		} //for���ֽ���
		cn += 2;
	}	//while����
	return 1;
}

