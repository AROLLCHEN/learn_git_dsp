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
	SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;// 开启GPIO时钟
	GpioCtrlRegs.GPAPUD.bit.GPIO0 = 0;    // 使能GPIO0 引脚内部上拉
	GpioCtrlRegs.GPAPUD.bit.GPIO1 = 0;   // 禁止GPIO1 引脚内部上拉
	GpioCtrlRegs.GPBPUD.bit.GPIO48 = 0;
	GpioCtrlRegs.GPBPUD.bit.GPIO49 = 0;
	GpioCtrlRegs.GPBPUD.bit.GPIO60 = 0;

	GpioCtrlRegs.GPAMUX1.all = 0;   // 配置GPIO0-GPIO15为通用I/O口
	GpioCtrlRegs.GPBMUX2.bit.GPIO48 = 0;
	GpioCtrlRegs.GPBMUX2.bit.GPIO49 = 0;
	GpioCtrlRegs.GPBMUX2.bit.GPIO60 = 0;

	GpioCtrlRegs.GPADIR.all = 0x00FFF;// 配置GPIO0-GPIO11为输出引脚
	GpioCtrlRegs.GPBDIR.bit.GPIO48=1;
	GpioCtrlRegs.GPBDIR.bit.GPIO49=1;
	GpioCtrlRegs.GPBDIR.bit.GPIO60=1;

	// 每个输入口可以有不同的输入限定
	// a) 输入与系统时钟 SYSCLKOUT同步
	// b) 输入被指定的采样窗口限定
	// c) 输入异步 (仅对外设输入有效)
	GpioCtrlRegs.GPAQSEL1.all = 0x0000;    // GPIO0-GPIO15与系统时钟SYSCLKOUT 同步
	GpioCtrlRegs.GPBQSEL2.bit.GPIO48=0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO49=0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO60=0;

	EDIS;

	//输出数据LCD_RS和LCD_EN清零
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
	DELAY_US(15000);//延迟15ms
	LCD12864_RSET_SETL;
	for (i=0; i<1000; i++);
	LCD12864_CS_SETL;
	LCD12864_RSET_SETH;

	//----------------Star Initial Sequence-------//
	//------程序初始化设置，具体命令可以看文件夹下---//

	//--软件初始化--//
	LCD12864_WriteCmd(0xE2);  //reset
	for (i=0; i<1000; i++);	   //延时一下

	//--表格第8个命令，0xA0段（左右）方向选择正常方向（0xA1为反方向）--//
	LCD12864_WriteCmd(0xA0);  //ADC select segment direction

	//--表格第15个命令，0xC8普通(上下)方向选择选择反向，0xC0为正常方向--//
	LCD12864_WriteCmd(0xC8);  //Common direction

	//--表格第9个命令，0xA6为设置字体为黑色，背景为白色---//
	//--0xA7为设置字体为白色，背景为黑色---//
	LCD12864_WriteCmd(0xA6);  //reverse display

	//--表格第10个命令，0xA4像素正常显示，0xA5像素全开--//
	LCD12864_WriteCmd(0xA4);  //normal display

	//--表格第11个命令，0xA3偏压为1/7,0xA2偏压为1/9--//
	LCD12864_WriteCmd(0xA2);  //bias set 1/9

	//--表格第19个命令，这个是个双字节的命令，0xF800选择增压为4X;--//
	//--0xF801,选择增压为5X，其实效果差不多--//
	LCD12864_WriteCmd(0xF8);  //Boost ratio set
	LCD12864_WriteCmd(0x01);  //x4

	//--表格第18个命令，这个是个双字节命令，高字节为0X81，低字节可以--//
	//--选择从0x00到0X3F。用来设置背景光对比度。---/
	LCD12864_WriteCmd(0x81);  //V0 a set
	LCD12864_WriteCmd(0x23);

	//--表格第17个命令，选择调节电阻率--//
	LCD12864_WriteCmd(0x25);  //Ra/Rb set

	//--表格第16个命令，电源设置。--//
	LCD12864_WriteCmd(0x2F);
	for (i=0; i<1000; i++);

	//--表格第2个命令，设置显示开始位置--//
	LCD12864_WriteCmd(0x40);  //start line

	//--表格第1个命令，开启显示--//
	LCD12864_WriteCmd(0xAF);  // display on
	for (i=0; i<1000; i++);
}

void LCD12864_ClearScreen(void)
{
	unsigned char i, j;

	for(i=0; i<8; i++)
	{
		//--表格第3个命令，设置Y的坐标--//
		//--Y轴有64个，一个坐标8位，也就是有8个坐标--//
		//所以一般我们使用的也就是从0xB0到0x07,就够了--//
		LCD12864_WriteCmd(0xB0+i);

		//--表格第4个命令，设置X坐标--//
		//--当你的段初始化为0xA1时，X坐标从0x10,0x04到0x18,0x04,一共128位--//
		//--当你的段初始化为0xA0时，X坐标从0x10,0x00到0x18,0x00,一共128位--//
		//--在写入数据之后X坐标的坐标是会自动加1的，我们初始化使用0xA0所以--//
		//--我们的X坐标从0x10,0x00开始---//
		LCD12864_WriteCmd(0x10);
		LCD12864_WriteCmd(0x00);

		//--X轴有128位，就一共刷128次，X坐标会自动加1，所以我们不用再设置坐标--//
		for(j=0; j<128; j++)
		{
			LCD12864_WriteData(0x00);  //如果设置背景为白色时，清屏选择0XFF
		}
	}
}

unsigned char LCD12864_Write16CnCHAR(unsigned char x, unsigned char y, unsigned char *cn)
{
	unsigned char j, x1, x2, wordNum;

	//--Y的坐标只能从0到7，大于则直接返回--//
	if(y > 7)
	{
		return 0;
	}

	//--X的坐标只能从0到128，大于则直接返回--//
	if(x > 128)
	{
		return 0;
	}
	y += 0xB0;	   //求取Y坐标的值
	//--设置Y坐标--//
	LCD12864_WriteCmd(y);
	while ( *cn != '\0')	 //在C语言中字符串结束以‘\0’结尾
	{

		//--设置Y坐标--//
		LCD12864_WriteCmd(y);

		x1 = (x >> 4) & 0x0F;   //由于X坐标要两句命令，分高低4位，所以这里先取出高4位
		x2 = x & 0x0F;          //去低四位
		//--设置X坐标--//
		LCD12864_WriteCmd(0x10 + x1);   //高4位
		LCD12864_WriteCmd(0x00 + x2);	//低4位

		for (wordNum=0; wordNum<50; wordNum++)
		{
		    //--查询要写的字在字库中的位置--//
			if ((CN16CHAR[wordNum].Index[0] == *cn)
			     &&(CN16CHAR[wordNum].Index[1] == *(cn+1)))
			{
				for (j=0; j<32; j++) //写一个字
				{
					if (j == 16)	 //由于16X16用到两个Y坐标，当大于等于16时，切换坐标
					{
						//--设置Y坐标--//
						LCD12864_WriteCmd(y + 1);

						//--设置X坐标--//
						LCD12864_WriteCmd(0x10 + x1);   //高4位
						LCD12864_WriteCmd(0x00 + x2);	//低4位
					}
					LCD12864_WriteData(CN16CHAR[wordNum].Msk[j]);
				}
				x += 16;
			}//if查到字结束
		} //for查字结束
		cn += 2;
	}	//while结束
	return 1;
}

