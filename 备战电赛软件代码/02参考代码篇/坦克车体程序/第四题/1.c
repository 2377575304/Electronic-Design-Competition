#include < reg52.h >
#include < intrins.h >
sbit P10=P1^0;
sbit P11=P1^1;
sbit P12=P1^2;
sbit P13=P1^3;
unsigned int PWM;
/*********************************************************/
void main()
{  
   	P10=1;P11=1;P10=1;P11=1;
    TMOD=0x21 ;
    TH0=(65536-50000)/256;//1ms延时常数 12M
    TL0=(65536-50000)%256; //频率调节
    TH1=(256-(250-PWM))/256;
    TL1=(256-(250-PWM))/256;  //脉宽调节
	EA=1;
    ET0=1;
    ET1=1;
    TR0=1 ;
	while(1)
	{}
}
/*********************************************************/
// 定时器0中断服务程序.
/*********************************************************/
void timer0() interrupt 1 
{  	unsigned int k;
    TR1=0 ;
    TH0=(65536-50000)/256;//1ms延时常数 12M
    TL0=(65536-50000)%256;//频率调节
    k++;
   if(k==100){PWM=250;}
   if(k==200){PWM=125;}	
   if(k==300){PWM=0;}
    if(k>300){k=0;}	
    TH1=PWM ;
    TR1=1 ;
    P10=1;P11=0;P12=1;P13=0;
}

/*********************************************************/
// 定时器1中断服务程序
/*********************************************************/
void timer1() interrupt 3 
{ 
    TR1=0 ;
   P10=0;P11=1;P12=0;P13=1;
}  


