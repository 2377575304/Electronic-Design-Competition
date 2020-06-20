#include <avr/io.h>
//#include <macros.h>

#define LcdBus PORTC
	
const unsigned char rs=3;
const unsigned char rw=4;
const unsigned char en=5;
const unsigned char psb=6;
const unsigned char rst=7;


/*------------------us延时子程序-----------------------------*/ 
void delayus(unsigned int us) 
{  unsigned int i; 
   us=us*5/4;
   for(i=0;i<us;i++); 
} 	


/*------------------ms延时子程序-----------------------------*/ 
void delayms(unsigned int ms) 
{  unsigned int i,j; 
   for(i=0;i<ms;i++) 
      for(j=0;j<1141;j++); 
} 


/*------------------忙检查--------------------------*/ 
void ChkBusy(void)
{
	DDRC=0X00;		//设置为输入
	PORTC=0X00;
	PORTD &=~BIT(rs);
	PORTD |=BIT(rw);
	PORTD |=BIT(en);
	while(PINC & 0X80);
	PORTD &=~BIT(en);
	DDRC=0XFF;		//设置为输出
}

/*------------------清屏命令--------------------------*/   
void clrscreen(void) 
{ 
    write_com(0x01); 
    delayms(2); 
} 


/*------------------初始化LCD--------------------------*/   
void LcdIni(void)
{
	DDRC=0XFF;
	PORTC=0XFF;
	DDRD=0XFF;
	PORTD=0XFF;
	
	PORTD &= ~BIT(rst);
	asm("NOP");
	PORTD |=BIT(rst);		     //复位
	
	delayms(5);
	write_com(0x30);             //选择基本指令集,选择8bit数据流
	delayms(5);
	write_com(0x01);             //清除显示，并且设定地址指针为00H
	delayms(5);
	write_com(0x06);             //指定在资料的读取及写入时，设定游标的移动方向及指定显示的移位
	delayms(5);	
	write_com(0x0c);             //开显示(无游标、不反白)
}


/*------------------写指令--------------------------*/ 
void write_com(unsigned char com)
{
	ChkBusy();
	PORTD &=~BIT(rs);
	PORTD &=~BIT(rw);
	PORTD &=~BIT(en);
	PORTC =com;
	PORTD |=BIT(en);
    delayus(10);
	PORTD &=~BIT(en);
}


/*------------------写数据--------------------------*/ 
void write_data(unsigned char dat)
{
	ChkBusy();
	PORTD |=BIT(rs);
	PORTD &=~BIT(rw);
	PORTD &=~BIT(en);
	PORTC=dat;
	PORTD |=BIT(en);
	delayus(10);
	PORTD &=~BIT(en);
}

