﻿#include "traffic.h"

void timer_init();

uint8_t vonat = 1;

void init()
{
	DDRA = PORTA_MASK;
	DDRE = PORTE_MASK;
	DDRC = PORTC_MASK;
	DDRF = PORTF_MASK;
	DDRB=DDRD=0xf0;
	DDRG=0x00;
	
	timer_init();
	
	sei();	
}

void timer_init()
{
	TIMSK |= (1<<OCIE0)|(1<<TOIE2);
	
	TCCR0 |= (1<<WGM01) | (1<<CS00)| (0<<CS01) | (1<<CS02);
	
	OCR0 = 124;
	
	TCCR2 |= (1<<CS20) ;
}

void kapcsol(char lampa, char allapot)
{
	switch(lampa)
	{
		case 1: //LB_Z2
			if(allapot == 'Z')
			{
				PORTA |= (1<<LB_Z2);
			}
			else if(allapot == 0)
			{
				PORTA &=  ~(1<<LB_Z2);
			}
		break;
		
		case 2: //LB
			switch(allapot)
			{
				case 'P':
				PORTA &= ~(1<<LB_S);
				PORTA &= ~(1<<LB_Z);
				PORTA |= (1<<LB_P);
				break;
				
				case 'S':
				PORTA &= ~(1<<LB_P);
				PORTA &= ~(1<<LB_Z);
				PORTA |= (1<<LB_S);
				break;
				
				case 'Z':
				PORTA &= ~(1<<LB_P);
				PORTA &= ~(1<<LB_S);
				PORTA |= (1<<LB_Z);
				break;
				
				case 'N':
				PORTA &= ~(1<<LB_Z);
				PORTA |= (1<<LB_P);
				PORTA |= (1<<LB_S);
				break;
				
				case 0:
				PORTA &= ~(1<<LB_P);
				PORTA &= ~(1<<LB_S);
				PORTA &= (1<<LB_Z);
				break;
			}
		break;
		
		case 3: //LA
			switch(allapot)
			{
				case 'P':
				PORTA &= ~(1<<LA_S);
				PORTA &= ~(1<<LA_Z);
				PORTA |= (1<<LA_P);
				break;
				
				case 'S':
				PORTA &= ~(1<<LA_P);
				PORTA &= ~(1<<LA_Z);
				PORTA |= (1<<LA_S);
				break;
				
				case 'Z':
				PORTA &= ~(1<<LA_P);
				PORTA &= ~(1<<LA_S);
				PORTA |= (1<<LA_Z);
				break;
				
				case 'N':
				PORTA &= ~(1<<LA_Z);
				PORTA |= (1<<LA_P);
				PORTA |= (1<<LA_S);
				break;
				
				case 0:
				PORTA &= ~(1<<LA_P);
				PORTA &= ~(1<<LA_S);
				PORTA &= (1<<LA_Z);
				break;
			}
		break;
		
		case 4: //LC
			switch(allapot)
			{
				case 'P':
				PORTC &= ~(1<<LC_S);
				PORTC &= ~(1<<LC_Z);
				PORTC |= (1<<LC_P);
				break;
				
				case 'S':
				PORTC &= ~(1<<LC_P);
				PORTC &= ~(1<<LC_Z);
				PORTC |= (1<<LC_S);
				break;
				
				case 'Z':
				PORTC &= ~(1<<LC_P);
				PORTC &= ~(1<<LC_S);
				PORTC |= (1<<LC_Z);
				break;
				
				case 'N':
				PORTC &= ~(1<<LC_Z);
				PORTC |= (1<<LC_P);
				PORTC |= (1<<LC_S);
				break;
				
				case 0:
				PORTC &= ~(1<<LC_P);
				PORTC &= ~(1<<LC_S);
				PORTC &= (1<<LC_Z);
				break;
			}
		break;
		
		case 5: //LE
			switch(allapot)
			{
				case 'P':
				PORTC &= ~(1<<LE_S);
				PORTC &= ~(1<<LE_Z);
				PORTC |= (1<<LE_P);
				break;
				
				case 'S':
				PORTC &= ~(1<<LE_P);
				PORTC &= ~(1<<LE_Z);
				PORTC |= (1<<LE_S);
				break;
				
				case 'Z':
				PORTC &= ~(1<<LE_P);
				PORTC &= ~(1<<LE_S);
				PORTC |= (1<<LE_Z);
				break;
				
				case 'N':
				PORTC &= ~(1<<LE_Z);
				PORTC |= (1<<LE_P);
				PORTC |= (1<<LE_S);
				break;
				
				case 0:
				PORTC &= ~(1<<LE_P);
				PORTC &= ~(1<<LE_S);
				PORTC &= (1<<LE_Z);
				break;
			}
		break;
		
		case 6: //LE_Z2
			if(allapot == 'Z')
			{
				PORTF |= (1<<LE_Z2);
			}
			else if(allapot == 0)
			{
				PORTF &=  ~(1<<LE_Z2);
			}
		break;
		
		case 7: //LD
			switch(allapot)
			{
				case 'P':
				PORTC &= ~(1<<LD_S);
				PORTC &= ~(1<<LD_Z);
				PORTA |= (1<<LD_P);
				break;
				
				case 'S':
				PORTA &= ~(1<<LD_P);
				PORTC &= ~(1<<LD_Z);
				PORTC |= (1<<LD_S);
				break;
				
				case 'Z':
				PORTA &= ~(1<<LD_P);
				PORTC &= ~(1<<LD_S);
				PORTC |= (1<<LD_Z);
				break;
				
				case 'N':
				PORTC &= ~(1<<LD_Z);
				PORTA |= (1<<LD_P);
				PORTC |= (1<<LD_S);
				break;
				
				case 0:
				PORTA &= ~(1<<LD_P);
				PORTC &= ~(1<<LD_S);
				PORTC &= (1<<LD_Z);
				break;
			}
		break;
		
		case 8: //LG1
			switch (allapot)
			{
				case 'Z':
				PORTE |= (1<<LG1_Z);
				PORTE &= ~(1<<LG1_P);
				PWM_villog(0);
				break;
				
				case 'P':
				PORTE &= ~(1<<LG1_Z);
				PORTE |= (1<<LG1_P);
				PWM_villog(0);
				break;
				
				case 'S':
				PWM_villog(8);
				break;
				
				case 0:
				PORTE &= ~(1<<LG1_Z);
				PORTE &= ~(1<<LG1_P);
				PWM_villog(0);
				break;
			}
		break;
		
		case 9: //LG2
			switch (allapot)
			{
				case 'Z':
				PORTE |= (1<<LG2_Z);
				PORTE &= ~(1<<LG2_P);
				PWM_villog(0);
				break;
				
				case 'P':
				PORTE &= ~(1<<LG2_Z);
				PORTE |= (1<<LG2_P);
				PWM_villog(0);
				break;
				
				case 'S':
				PWM_villog(9);
				break;
				
				case 0:
				PORTE &= ~(1<<LG2_Z);
				PORTE &= ~(1<<LG2_P);
				PWM_villog(0);
				break;
			}
		break;
		
		case 'V':
			if(allapot == 'P')
			{
				vonat = 0;
				
				
			}
			if(allapot == 'F')
			{
				vonat = 1;
				PORTF &= ~(1<<LV_P1);
				PORTF &= ~(1<<LV_P2);
			}
		break;
		
		default:
		break;
		
	}
}