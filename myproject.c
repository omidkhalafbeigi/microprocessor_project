#include <mega32.h>
#include <io.h>
#include <delay.h>
bit x=0, x1=0;
interrupt [EXT_INT0] void ext_int0_isr(void)
{
    x=~x;
    PORTA.0=x;
    delay_ms(20);
}
interrupt [EXT_INT1] void ext_int1_isr(void)
{
    x1=~x1;
    PORTA.1=x1;
    delay_ms(20);
}
void main(void)
{
unsigned char l_1;
DDRA = 0x03;
DDRB = 0xFF;
PORTA=0;
GICR = (1 << INT1) | (1 << INT0) | (0 << INT2);
MCUCR = (1 << ISC11) | (1 << ISC10) | (0 << ISC01) | (0 << ISC00);
GIFR = (1 << INTF1) | (1 << INTF0) | (0 << INTF2);
#asm("sei");
PORTB = 0x01;
while (1)
      {
          PORTB = 0x01;   
          for (l_1=0; l_1<7; l_1++)
          {       
            delay_ms(75);
            PORTB = PORTB * 2;
          }                   
          for (l_1=0; l_1<7; l_1++)
          {       
            delay_ms(75);
            PORTB = PORTB / 2;
          }
      }
}
