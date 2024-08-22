/*
 * main.c
 *
 *  Created on: Jul 31, 2024
 *      Author: !?
 */

#include<util/delay.h>
#include <avr/io.h>
typedef int u8;


// not true

int main()
{
	int seg_cth[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	DDRA =0x7f;
	DDRB =0x7f;
	DDRC =0xff;
	//DDRC =0x69;
	DDRD =0xff;
	PORTA |= (1<<7);  // i want bit number 7 is one
	PORTB |= (1<<7);
	PORTA=0x80 |0x77;
	PORTB=0x80|seg_cth[2];
	PORTC=seg_cth[0];
	PORTD=seg_cth[5];
	while(1)
	{
	if(((PINA>>7)&1)==0 && ((PINB>>7)&1)==0)
		{
			PORTC=seg_cth[0];  //d
			PORTD=seg_cth[5];  //s
			PORTA= 0x80|0x77;      //A
			PORTB = 0x80|seg_cth[2]; //z
			_delay_ms(200);
			PORTC ^=seg_cth[0];
			PORTD ^=seg_cth[5];
			_delay_ms(200);
		}

	else if(((PINA>>7)&1)==1 && ((PINB>>7)&1)==0)
		{
			PORTC=seg_cth[0];
			PORTD=seg_cth[5];
			PORTA= 0x80|0x77;      //A
			PORTB = 0x80|seg_cth[2]; //z
			_delay_ms(200);
			PORTA=0x80;
			PORTB=0x80;
			_delay_ms(200);

			}

	else if(((PINA>>7)&1)==0 && ((PINB>>7)&1)==1)
			{
				PORTC=seg_cth[0];
				PORTD=seg_cth[5];
				PORTA =0x80;
				PORTB=0x80;
				_delay_ms(200);
			    PORTA =0x80|0x77;
				PORTB=0x80|seg_cth[2];
				PORTC ^=seg_cth[0];
				PORTD ^=seg_cth[5];
				_delay_ms(200);
				}

	else if(((PINA>>7)&1)==1 && ((PINB>>7)&1)==1)
				{
				    PORTA=0x80|0x77;
					PORTB =0x80|seg_cth[2];
					//_delay_ms(200);

					PORTC=seg_cth[0];
					PORTD=seg_cth[5];
					_delay_ms(200);
					PORTC ^=seg_cth[0];
					PORTD ^=seg_cth[5];
					PORTA=0x80;
                    PORTB=0x80;
                    _delay_ms(200);
					}

    }
}







/*
int main ()
{
	int seg_cth[]={0x3f,0x6d,0x77,0x5b};   //D,S, ,A,Z
	DDRA=DDRB=0x7f;       // o111 1111 :becouse switch input on bit number 8 on porta,b
	DDRC=DDRD=0xff;      //1111 1111  :seegment is output
	PORTA |=1<<7;       // becouse switch pull up
	PORTB |=1<<7;      // becouse switch pull up

	// out i want all is turn on

	PORTC=seg_cth[0];
	PORTD=seg_cth[1];
	PORTA =0x80|seg_cth[2];  // 1000 0000 | 0111 0111 => 1111 1111
	PORTB =0x80|seg_cth[3];  // 1000 0000 | 0101 1011 => 1111 1011
	while(1)
	{
		if(((PINA>>7)&1)==1 && ((PINB>>7)&1)==1)    // 2 are off
		{
			PORTC =seg_cth[0];
			PORTD =seg_cth[1];
			PORTA =0x80|seg_cth[2];
			PORTB =0x80|seg_cth[3];
			_delay_ms(200);
			PORTC ^=PORTC;     // turn  off
			PORTD ^=PORTD;
			PORTA =0x80;     // 0x 1000 0000
			PORTB =0x80;
			_delay_ms(200);
		}
		else if(((PINA>>7)&1)==0 && ((PINB>>7)&1)==1)     // pina is on ,  pinb is off
		{

			PORTC=seg_cth[0];
			PORTD=seg_cth[1];
			PORTA =0x80|seg_cth[2];
			PORTB =0x80|seg_cth[3];
			_delay_ms(200);
			PORTA =0x80;
			PORTB =0x80;
			_delay_ms(200);


		}
		else if(((PINA>>7)&1)==1 && ((PINB>>7)&1)==0)       // pinb is on , pina is off
		{

			PORTC =seg_cth[0];
			PORTD =seg_cth[1];
			PORTA =0x80|seg_cth[2];
			PORTB =0x80|seg_cth[3];
			_delay_ms(200);
			PORTA = 0x80;
			PORTB =0x80;
			_delay_ms(200);

		}
		else if(((PINA>>7)&1)==0 && ((PINB>>7)&1)==0)          // 2 are on
		{

			PORTC =seg_cth[0];
			PORTD =seg_cth[1];
			PORTA =0x80|seg_cth[2];
			PORTB =0x80|seg_cth[3];
			_delay_ms(200);
			PORTC ^=PORTC;
			PORTD ^=PORTD;
			_delay_ms(200);

		}



	}

}

*/





/*

true
int main()
{
char letters[] = {0x77, 0x5B, 0x3F, 0x6D};

 DDRA = DDRB = 0x7F;
 DDRC = DDRD = 0xFF;
 PORTA |= (1<<7);
 PORTB |= (1<<7);
 PORTA = 0x80 | letters[0];
 PORTB = 0x80 | letters[1];
 PORTC = letters[2];
 PORTD = letters[3];


 while(1)
 {
  if(((PINA>>7) & 1) == 1 && ((PINB>>7) & 1) == 1)
  {
   PORTA = 0x80 | letters[0];
   PORTB = 0x80 | letters[1];
   PORTC = letters[2];
   PORTD = letters[3];
   _delay_ms(500);
   PORTA = PORTB = 0x80;
   PORTC ^= PORTC;
   PORTD ^= PORTD;
   _delay_ms(500);
  }
  else if(((PINA>>7) & 1) == 0 && ((PINB>>7) & 1) == 1)
  {
   PORTC = letters[2];
   PORTD = letters[3];
   PORTA = PORTB = 0x80;
   _delay_ms(500);
   PORTC ^= PORTC;
   PORTD ^= PORTD;
   PORTA = 0x80 | letters[0];
   PORTB = 0x80 | letters[1];
   _delay_ms(500);
  }
  else if(((PINA>>7) & 1) == 1 && ((PINB>>7) & 1) == 0)
  {
   PORTC = letters[2];
   PORTD = letters[3];
   PORTA = 0x80 | letters[0];
   PORTB = 0x80 | letters[1];
   _delay_ms(500);
   PORTA = PORTB = 0x80;
   _delay_ms(500);

  }
  else if(((PINA>>7) & 1) == 0 && ((PINB>>7) & 1) == 0)
  {
   PORTC = letters[2];
   PORTD = letters[3];
   PORTA = 0x80 | letters[0];
   PORTB = 0x80 | letters[1];
   _delay_ms(500);
   PORTC ^= PORTC;
   PORTD ^= PORTD;
   _delay_ms(500);
  }

  //else
  //{

  //}

 }
    return 0;
}





*/




/*
 * int main()
{
	int seg_cth[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	DDRA =0x7f;
	DDRB =0x7f;
	DDRC =0xff;
	//DDRC =0x69;
	DDRD =0xff;
	PORTA |=1<<7;  // i want bit number 7 is one
	PORTB |=1<<7;
	PORTA=0;
	PORTB=0;
	PORTC=0;
	PORTD=0;
	while(1)
	{
	if(((PINA>>7)&1)==0 && ((PINB>>7)&1)==0)
		{
			PORTC=seg_cth[0];  //d
			PORTD=seg_cth[5];  //s
			//PORTC=PORTC & (00111001);  //c
			//PORTC=seg_cth[0x69];
			//PORTA=seg_cth[0x77];
			PORTA= 0x80|0x77;      //A
			PORTB = 0x80|seg_cth[2]; //z
			_delay_ms(200);
			PORTC ^=seg_cth[0];
			PORTD ^=seg_cth[5];
			//PORTC=PORTC & (0x00);
			//PORTC=seg_cth[0];
			_delay_ms(200);
		}

	else if(((PINA>>7)&1)==1 && ((PINB>>7)&1)==0)
		{
			PORTC=seg_cth[0];
			PORTD=seg_cth[5];
			//PORTC = PORTC & (00111001);
			//PORTC=seg_cth[0x69];
			PORTA= 0x80|0x77;      //A
			PORTB = 0x80|seg_cth[2]; //z
			_delay_ms(200);
			PORTA=0x80;
			PORTB=0x80;
			//PORTC=PORTC & (0x00);
			//PORTC=seg_cth[0];

		    //PORTA=seg_cth[0x77];
		//	PORTA=0x77;
		//	PORTB=seg_cth[2];
		//	_delay_ms(200);
		 //   PORTA=seg_cth[0];
	//		PORTB=seg_cth[0];

			}

	else if(((PINA>>7)&1)==0 && ((PINB>>7)&1)==1)
			{
				PORTC=seg_cth[0];
				PORTD=seg_cth[5];
				//PORTC=PORTC & (00111001);
				//PORTC=seg_cth[0x69];
				//_delay_ms(200);

			    //PORTA=seg_cth[0x77];
				PORTA =0x80;
				PORTB=0x80;
				_delay_ms(200);
			    PORTA =0x80|0x77;
				PORTB=0x80|seg_cth[2];
				PORTC ^=seg_cth[0];
				PORTD ^=seg_cth[5];
				}

	else if(((PINA>>7)&1)==1 && ((PINB>>7)&1)==1)
				{
				    //PORTA=seg_cth[0x77];
				    PORTA=0x80|0x77;
					PORTB =0x80|seg_cth[2];
					//_delay_ms(200);

					PORTC=seg_cth[0];
					PORTD=seg_cth[5];
					//PORTC=PORTC & (00111001);
					//PORTC=seg_cth[0x69];
					_delay_ms(200);
					PORTC ^=seg_cth[0];
					PORTD ^=seg_cth[0];
					//PORTC=PORTC & (0x00);
					//PORTC=seg_cth[0];
					PORTA=0x80;
                    PORTB=0x80;
					}

    }
}

*/














