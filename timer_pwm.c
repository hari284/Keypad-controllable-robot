#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
unsigned char x,y=0;
unsigned long int i=0;
#define lcd PORTC
#include<mamalib/lcd.h>
#include<mamalib/keypad.h>
void timer_fast_pwm()
{
  TCCR0=(1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS00);//(1<<cs00)...cpu frequency
}
void main()
{
 DDRA=0b11110000;
 PORTA=0b00001111;
 DDRD=0xff;
 DDRB=0xff;//making pb3 high to work as o/p to collect o/p of timer0
 //PORTB=0b00001010;//M1 AND M2
 DDRC=0xff;
 
 timer_fast_pwm();
 lcd_init();
 while(1)
 {
   ////////////////////LED
  /*for(int i=0;i<255;i++)
  {
   OCR0=i;
   _delay_ms(3);
  }
  for(int i=255;i>=0;i--)
  {
   OCR0=i;
   _delay_ms(3);
  }*
  ///////////motor
 /* for(int i=0;i<100;i++)//THIS FIRST LOOP WONT GIVE THAT MUCH O/P TO RUN MOTOR
  {
   OCR0=i;
  }*/
  //start:
  
  
  x=keypad_calc();
  //PORTB=0b00010000;
  lcd_command(0x80);
	  lcd_data(x);
  if(x=='1'|x=='2'|x=='3'|x=='4'|x=='5')
  {    
	  
	  switch(x)
	  {         start:
		     case '1':for(i=100;i<150;i++)
			          {PORTB=0b00011001;///+led
					    OCR0=i;
						lcd_command(0x83);
					   lcd_string("   ");
					   lcd_command(0x85);
					   lcd_infinity_number(i);
					   while((PINA&0b00001111)!=0b00001111)
					   {
					     
					     if(PINA==0b00001101)
							goto case2;
						  if(PINA==0b00001011)
						   goto case3;
						  
						  
						    
                           
					   }
					  }
					    break;


			case '2':
			case2:
			for(i=150;i<200;i++)
			          {PORTB=0b00011001;
					    OCR0=i;
						lcd_command(0x83);
					   lcd_string("   ");
					   lcd_command(0x85);
					   lcd_infinity_number(i);
					  
					  }
					  break;


		    case '3':
			case3:
			for(;OCR0>0;OCR0--)
			          {PORTB=0b00011001;
					    
						lcd_command(0x83);
					   lcd_string("   ");
					   lcd_command(0x85);
					   lcd_infinity_number(OCR0);
					  
					  }
					  break;
					 
					
		    
		    case '4':
		       case4:
		       for(;OCR0>0;OCR0--)
			          {PORTB=0b00011001;
					    
					   lcd_command(0x83);
					   lcd_string("   ");
					   lcd_command(0x85);
					   lcd_infinity_number(OCR0);
					   
					  }
				for(i=100;i<150;i++)
			          { PORTB=0b00011110;
					    OCR0=i;
						lcd_command(0x83);
					   lcd_string("   ");
					   lcd_command(0x85);
					   lcd_infinity_number(i);
					  
					  }
			         break;

					 default:
					 case5:
					 for(;OCR0>0;OCR0--)
			          {PORTB=0b00011001;
					    
					   lcd_command(0x83);
					   lcd_string("   ");
					   lcd_command(0x85);
					   lcd_infinity_number(OCR0);}
					 PORTB=0b00001111;
					 break;
	  }
	   
   }
  

 }
}
