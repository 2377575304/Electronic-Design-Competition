/*****************************************************
This program was produced by the
CodeWizardAVR V2.03.4 Standard
Automatic Program Generator
?Copyright 1998-2008 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 2009-7-19
Author  : 
Company : 
Comments: 


Chip type           : ATmega16L
Program type        : Application
Clock frequency     : 16.000000 MHz
Memory model        : Small
External RAM size   : 0
Data Stack size     : 256
*****************************************************/
/*connect us:
Web:https://sites.google.com/site/journeybuaa/
Email:stingshen1@gmail.com

 */

#include <mega16.h>
#include <delay.h>
#define RXB8 1
#define TXB8 0
#define UPE 2
#define OVR 3
#define FE 4
#define UDRE 5
#define RXC 7

#define FRAMING_ERROR (1<<FE)
#define PARITY_ERROR (1<<UPE)
#define DATA_OVERRUN (1<<OVR)
#define DATA_REGISTER_EMPTY (1<<UDRE)
#define RX_COMPLETE (1<<RXC)

// USART Receiver buffer
#define RX_BUFFER_SIZE 64
#define MyAddress 0x01      // 自己的地址
/**************变量声明***************/
char rx_buffer[RX_BUFFER_SIZE];

#if RX_BUFFER_SIZE<256
unsigned char rx_wr_index,rx_rd_index,rx_counter;
#else
unsigned int rx_wr_index,rx_rd_index,rx_counter;
#endif
// This flag is set on USART Receiver buffer overflow
bit rx_buffer_overflow;
// USART Receiver interrupt service routine
char str[] = "hello\n";
char frameData[16];
char state;
bit statechanged = 0;
/***************函数声明****************/
char doFrameOk();
void doCommand();
void uartSend(char sendCmd, char sendData);
void balan();
void move(char mode);
interrupt [USART_RXC] void usart_rx_isr(void)
{
char status,data;
status=UCSRA;
data=UDR;
if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0)
   {
   rx_buffer[rx_wr_index]=data;
   if (++rx_wr_index == RX_BUFFER_SIZE) rx_wr_index=0;
   if (++rx_counter == RX_BUFFER_SIZE)
      {
      rx_counter=0;
      rx_buffer_overflow=1;
      };
   };
}

#ifndef _DEBUG_TERMINAL_IO_
// Get a character from the USART Receiver buffer
#define _ALTERNATE_GETCHAR_
#pragma used+
char getchar(void)
{
char data;

unsigned int i;
for(i=0;i<(unsigned int)(16*143-2);i++)
    if(rx_counter!=0)
        break;



data=rx_buffer[rx_rd_index];
if (++rx_rd_index == RX_BUFFER_SIZE) rx_rd_index=0;
#asm("cli")
--rx_counter;
#asm("sei")
return data;
}
#pragma used-
#endif

// Standard Input/Output functions
#include <stdio.h>

// Declare your global variables here

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTA=0x00;
DDRA=0x00;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0x00;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0x00;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0x00;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=FFh
// OC0 output: Disconnected
TCCR0=0x00;
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer 1 Stopped
// Mode: Normal top=FFFFh
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer 1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer 2 Stopped
// Mode: Normal top=FFh
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 19200
UCSRA=0x00;
UCSRB=0x98;
UCSRC=0x86;
UBRRH=0x00;
UBRRL=0x33;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// Global enable interrupts
DDRA=0xf0;
PORTA = 0x00;
PORTD=0x00;
DDRD=0x30;
// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 250.000 kHz
// Mode: Ph. correct PWM top=01FFh
// OC1A output: Non-Inv.
// OC1B output: Non-Inv.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer 1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0xa2;
TCCR1B=0x12;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;
ACSR=0x80;
ICR1H = 0x01;
ICR1L = 0xf0;
#asm("sei")
puts(str);
while (1)
{
//   Place your code here
    if(getchar() == 0x55)
    {        
        if(doFrameOk())
        {
         doCommand();
        }
    }
    balan();
};
}
void balan()
{
    switch(state)
    {
        case 1:
                move(4);
                delay_ms(250);
                move(0);
                delay_ms(250);
            break;
        case 2:
                move(3);
                delay_ms(250);
                move(0);
                delay_ms(250);
            break;
        case 3:
            move(0);
            break;
        default:
            move(0);
            break;
    }
}
/*************移动函数(0:停止, 1:全速前行,2:全速后退, 3:慢速前行, 4:慢速后退) **********************/
void move(char mode)
{
    switch(mode)
    {
        case 0:
            //刹车命令
            PORTA.4 = PORTA.6 = ~PORTA.4;
            PORTA.5 = PORTA.7 = ~PORTA.5;
            OCR1A = OCR1B = 0x00ee;
            delay_ms(250);
            //有必要时加上倾角检测命令

            PORTA.4 = PORTA.6 = 0;
            PORTA.5 = PORTA.7 = 0;
            OCR1A = OCR1B = 0x01f0;
            putchar('4');
            break;
        case 1:
            PORTA.4 = PORTA.6 = 0;
            PORTA.5 = PORTA.7 = 1; 
            OCR1AH = OCR1BH = 0x01;
            OCR1AL = OCR1BL = 0xf0;
            putchar('2');
            break;
        case 2:
            PORTA.4 = PORTA.6 = 1;
            PORTA.5 = PORTA.7 = 0; 
            OCR1AH = OCR1BH = 0x01;
            OCR1AL = OCR1BL = 0xf0;
            putchar('3');
            break;
        case 3:
            PORTA.4 = PORTA.6 = 0;
            PORTA.5 = PORTA.7 = 1; 
            OCR1AH = OCR1BH = 0x01;
            OCR1AL = OCR1BL = 0x40;
            putchar('2');
            break;
        case 4:
            PORTA.4 = PORTA.6 = 1;
            PORTA.5 = PORTA.7 = 0; 
            OCR1AH = OCR1BH = 0x01;
            OCR1AL = OCR1BL = 0x40;
            putchar('3');
            break;
    }
}
char doFrameOk()
{
    char flag=0, k=0,i,frameLen;
    if(getchar() == 0xaa)
        k++;
    if(getchar() == MyAddress)
        k++;
    if(k == 2)
    {
        flag = 1;
        frameLen = getchar();
        for(i = 0;i < frameLen; i++)
        {
            frameData[i] = getchar();
        }
        
    }
    return flag;
}
void doCommand()
{
//    int i = 1;
    switch(frameData[0])
    {
        case 0x01: uartSend(0xff, 0x00);
        break;
        case 0x02:
            PORTA.4 = PORTA.6 = 1;
            PORTA.5 = PORTA.7 = 0; 
            OCR1AH = OCR1BH = frameData[1];
            OCR1AL = OCR1BL = frameData[2];
            putchar('2');
            break;
        case 0x03: 
            PORTA.4 = PORTA.6 = 0;
            PORTA.5 = PORTA.7 = 1;
            OCR1AH = OCR1BH = frameData[1];
            OCR1AL = OCR1BL = frameData[2];
            putchar('3');
            break;
        case 0x04:
//刹车命令
            PORTA.4 = PORTA.6 = ~PORTA.4;
            PORTA.5 = PORTA.7 = ~PORTA.5;
            OCR1A = OCR1B = 0x00ee;
            delay_ms(250);
//倾角检测命令
//            if(state == 1)
//            {
//                PORTA.4 = PORTA.6 = 1;
//                PORTA.5 = PORTA.7 =  
//            }
//            if
            PORTA.4 = PORTA.6 = 0;
            PORTA.5 = PORTA.7 = 0;
            OCR1A = OCR1B = 0x01f0;
            putchar('4');
            break;
        case 0x05:
            PORTA.4 = PORTA.7 = 1;
            PORTA.5 = PORTA.6 = 0;
            OCR1AH = OCR1BH = frameData[1];
            OCR1AL = OCR1BL = frameData[2];
            putchar('5');
            break;
        case 0x06:
            PORTA.4 = PORTA.7 = 0;
            PORTA.5 = PORTA.6 = 1;
            OCR1AH = OCR1BH = frameData[1];
            OCR1AL = OCR1BL = frameData[2];
            putchar('6');
            break;
        case 0x07:
            PORTA.4 = PORTA.6 = 1;
            PORTA.5 = PORTA.7 = 0;
            OCR1AH = frameData[1];
            OCR1AL = frameData[2];
            OCR1BH = frameData[3];
            OCR1BL = frameData[4];
            putchar('7');
            break;
        case 0x08:
            PORTA.4 = PORTA.6 = 0;
            PORTA.5 = PORTA.7 = 1;
            OCR1AL = frameData[1];
            OCR1AL = frameData[2];
            OCR1BH = frameData[3];
            OCR1BL = frameData[4];
            putchar('8');
            break;
    //接受平衡状态指示        
        case 0x09:
            state = 1;
            statechanged = 1;
            putchar('9');
            break;
        case 0x0a:
            state = 2;
            statechanged = 1;
            putchar('a');
            break;
        case 0x0b:
            state = 3;
            statechanged = 1;
            putchar('b');
            break;           
        default: uartSend(0xee, 0x00);
    }     
}
void uartSend(char sendCmd, char sendData)
{
        putchar(0x55);
        putchar(0xaa);
        putchar(0x02);
        putchar(sendCmd);
        putchar(sendData);
        putchar('\n');               
}