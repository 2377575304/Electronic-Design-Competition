/*
	LCD1602液晶屏四线驱动模块
	1、可直接嵌入到项目中使用
	2、晶振频率：1M
	3、如晶振提高低层驱动延时要作相应修改
	4、程序在原来基础上只使用了PB口的高四位，即PB4—PB7，PB0—PB3可以做它用
     
	SunnyTrip
	www.iccavr.com
*/
//未使用的函数建议注释掉,同时把头文件里的函数定义注释掉
  /* ADC */
/* Analog Comparator */
/* USART */
/* SPI */
/* EEPROM */
/* Watchdog Timer Control Register */
/* Timer/Counter 2 */
/* Timer/Counter 1 */
/* Special Function I/O register */
/* Timer/Counter 0 */
/* MCU general */
/* SPM Conrol Register */
/* Timer/Counter Interrupts */
/* General Interrupts */
/* Port A bits */
/* Port B bits */
/* Port C bits */
/* Port D bits */
/* Lock and Fuse Bits with LPM/SPM instructions */
/* lock bits */
/* fuses low bits */
/* fuses high bits */
   typedef unsigned char  uchar;			/* 定义可移植的无符号8位整数关键字    */
typedef signed   char  schar;			/* 定义可移植的有符号8位整数关键字    */
typedef unsigned int   uint;			/* 定义可移植的无符号16位整数关键字   */
typedef signed   int   sint;			/* 定义可移植的有符号16位整数关键字   */
typedef unsigned long  ulong;			/* 定义可移植的无符号32位整数关键字   */
typedef signed   long  slong;			/* 定义可移植的有符号32位整数关键字   */
// CodeVisionAVR C Compiler
// (C) 1998-2001 Pavel Haiduc, HP InfoTech S.R.L.
// I/O registers definitions for the ATmega16
#pragma used+
sfrb TWBR=0;
sfrb TWSR=1;
sfrb TWAR=2;
sfrb TWDR=3;
sfrb ADCL=4;
sfrb ADCH=5;
sfrw ADCW=4;      // 16 bit access
sfrb ADCSRA=6;
sfrb ADMUX=7;
sfrb ACSR=8;
sfrb UBRRL=9;
sfrb UCSRB=0xa;
sfrb UCSRA=0xb;
sfrb UDR=0xc;
sfrb SPCR=0xd;
sfrb SPSR=0xe;
sfrb SPDR=0xf;
sfrb PIND=0x10;
sfrb DDRD=0x11;
sfrb PORTD=0x12;
sfrb PINC=0x13;
sfrb DDRC=0x14;
sfrb PORTC=0x15;
sfrb PINB=0x16;
sfrb DDRB=0x17;
sfrb PORTB=0x18;
sfrb PINA=0x19;
sfrb DDRA=0x1a;
sfrb PORTA=0x1b;
sfrb EECR=0x1c;
sfrb EEDR=0x1d;
sfrb EEARL=0x1e;
sfrb EEARH=0x1f;
sfrw EEAR=0x1e;   // 16 bit access
sfrb UBRRH=0x20;
sfrb UCSRC=0X20;
sfrb WDTCR=0x21;
sfrb ASSR=0x22;
sfrb OCR2=0x23;
sfrb TCNT2=0x24;
sfrb TCCR2=0x25;
sfrb ICR1L=0x26;
sfrb ICR1H=0x27;
sfrb OCR1BL=0x28;
sfrb OCR1BH=0x29;
sfrw OCR1B=0x28;  // 16 bit access
sfrb OCR1AL=0x2a;
sfrb OCR1AH=0x2b;
sfrw OCR1A=0x2a;  // 16 bit access
sfrb TCNT1L=0x2c;
sfrb TCNT1H=0x2d;
sfrw TCNT1=0x2c;  // 16 bit access
sfrb TCCR1B=0x2e;
sfrb TCCR1A=0x2f;
sfrb SFIOR=0x30;
sfrb OSCCAL=0x31;
sfrb OCDR=0x31;
sfrb TCNT0=0x32;
sfrb TCCR0=0x33;
sfrb MCUCSR=0x34;
sfrb MCUCR=0x35;
sfrb TWCR=0x36;
sfrb SPMCR=0x37;
sfrb TIFR=0x38;
sfrb TIMSK=0x39;
sfrb GIFR=0x3a;
sfrb GICR=0x3b;
sfrb OCR0=0X3c;
sfrb SPL=0x3d;
sfrb SPH=0x3e;
sfrb SREG=0x3f;
#pragma used-
// Interrupt vectors definitions
// Needed by the power management functions (sleep.h)
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x40
	.EQU __sm_mask=0xB0
	.EQU __sm_powerdown=0x20
	.EQU __sm_powersave=0x30
	.EQU __sm_standby=0xA0
	.EQU __sm_ext_standby=0xB0
	.EQU __sm_adc_noise_red=0x10
	.SET power_ctrl_reg=mcucr
	#endif
#endasm
extern unsigned char TWI_Send(uchar Slave,uchar Address,uchar Data);
//extern unsigned char TWI_SendStr(unsigned char Slave,unsigned char Address,unsigned char *Array,unsigned char CNT);
extern unsigned char TWI_Receive(unsigned char Slave,unsigned char Address);
// CodeVisionAVR C Compiler
// (C) 1998-2000 Pavel Haiduc, HP InfoTech S.R.L.
#pragma used+
void delay_us(unsigned int n);
void delay_ms(unsigned int n);
#pragma used-
extern  void Init_IO ( void );
extern  void  Init_T1(  void );
extern  void Init_T0( void );
extern  void Init_T2( void );
extern  void Init_device( void ) ;
extern  void Init_TWI(void); 
//extern    unsigned char Read_PCF8563T(unsigned char Address);
extern    void Write_PCF8563T(unsigned char Address , char date);
extern   void start_PCF( void );
extern    char Read_sec( void);
extern   char Read_miu( void );
void LCD_init(void);
void LCD_clear(void);
void LCD_write_str(unsigned char X,unsigned char Y,unsigned char flash *s);
void LCD_write_char(unsigned char X,unsigned char Y,unsigned char data);
void LCD_write_com(unsigned char com);
//void CursorScroll(void);  
//void ScreenScroll(void);
void LCDsetxy(unsigned char x , unsigned char y)
 {
  	 if (y == 0) 
 	 	{
    	 LCD_write_com(0x80 + x);
    	}
    else 
		{
    	 LCD_write_com(0xC0 + x);
    	}
  }
/*显示屏命令写入函数*/
void LCD_write_com(unsigned char com) {
		PORTA.1=0;
	PORTA.2=0;
	PORTA.3=1  ;
	PORTA&=0x0f;
	PORTA|= com&0xf0;
	com = com<<4;
	PORTA.3=0;
	delay_us( 10);
	PORTA.3=1  ;
	PORTA&=0x0f;
	PORTA|= com&0xf0;
	PORTA.3=0;
	delay_us(10);
}
/*显示屏命令写入函数*/
void LCD_write_data(unsigned char data) {
	PORTA.1=1;
	PORTA.2=0;
	PORTA.3=1  ;
	PORTA&=0x0f;
	PORTA|= data&0xf0;
	data = data<<4;
	PORTA.3=0;
	delay_us( 10);
	PORTA.3=1  ;
	PORTA&=0x0f;
	PORTA|= data&0xf0;
	PORTA.3=0;
}
/*显示屏清空显示*/
void LCD_clear(void) {
	LCD_write_com(0x01);
	delay_ms( 15);
}
/*显示屏字符串写入函数*/
void LCD_write_str(unsigned char x,unsigned char y,unsigned char flash *s) {
	    uchar i=0;
    LCDsetxy( x ,  y);
    while (*s) {
    	LCD_write_data(*s);
    	i++;
    	s ++;
    	}
}
/*显示屏单字符写入函数*/
void LCD_write_char(unsigned char x,unsigned char y,unsigned char data) {
	    LCDsetxy( x ,  y);
        LCD_write_data( data);  
}       
/*void CursorScroll(void)
{
	
    LCD_write_com(0x10);	//光标左移
   
}      
void ScreenScroll(void)
{
	
	LCD_write_com(0x18);		//画面左滚
	delay_ms(255);
		
} */
/*显示屏初始化函数*/
void LCD_init(void)
 {
								/*I/O口方向设置*/
	LCD_write_com(0x28);				/*显示模式设置*/
	delay_ms( 15);
	LCD_write_com(0x28);
	delay_ms( 5);
	LCD_write_com(0x28);
	delay_ms( 5);
	LCD_write_com(0x28);
		LCD_write_com(0x08);				/*显示关闭*/
	LCD_write_com(0x01);				/*显示清屏*/
	LCD_write_com(0x06);				/*显示光标移动设置*/
	delay_ms( 5);
	LCD_write_com(0x0c);				/*显示开及光标设置*/
}
