#include<xc.h>
#include<pic18f458.h>
#pragma config WDT=OFF
#define _XTAL_FREQ 40000000
#define dataline PORTD
#define rs PORTCbits.RC0
#define rw PORTCbits.RC1
#define e PORTCbits.RC2
void display(unsigned char ch);
void trigger();
void main()
{ TRISD=0;
  TRISC=0;
  unsigned char data[]="Hello universe so wassuppp hoomans xyz";
  rs=0;
  rw=0;
  dataline=0x01;
  trigger();
  dataline=0x38;
  trigger();
  dataline=0x0e;
  trigger();
  dataline=0x80;
  trigger();
  rs=1;
  for(unsigned int i=0;data[i]!='\0';i++)
  { if(i>=16)
     {  rs=0;
        dataline=0x18;
        trigger();
        rs=1;
     }
    display(data[i]);
  }
  __delay_ms(15);
}
void display(unsigned char ch)
{ dataline=ch;
  e=1;
  __delay_ms(15);
  e=0;
} 
void trigger()
{ e=1;
  __delay_ms(15);
  e=0;
}
