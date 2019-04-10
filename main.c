

#include <avr/io.h>
#include<avr/interrupt.h>
#include<avr/delay.h>


void initADC()
{
    ADMUX|=(1<<REFS0);//max resolution of 5v
    ADCSRA=(1<<ADEN)|(7<<ADPS0);//set 128

}
uint16_t ReadADC(uint8_t ch)//count s 0 to 7
{
        ADMUX&=0Xf8;
        ch=ch&0b00000111;//mux 0 1 2 are set
        ADMUX|=ch;

        ADCSRA|=(1<<ADSC);//start convertion
        while(!(ADCSRA&(1<<ADIF)));//wait till its over
        ADCSRA|=(1<<ADIF);//flag s raised to tell fst code s converted
        return(ADC);// Insert code
    }
int main(void)

{



    // Insert code

    TCCR1A|=((1<<COM1A1)|(1<< WGM10)|(1<<WGM11));

    TCCR1B|=((1<<WGM12)|(1<<CS11)|(1<<CS10));

    TCNT1=0x00;

    //OCR1A=50;
    DDRC&=~(1<<PC0);
    DDRB|=(1<<PB1);


initADC();
uint16_t x =0;


    while(1)

    {


x=ReadADC(0);

          OCR1A=x;


    }



    return 0;

}
