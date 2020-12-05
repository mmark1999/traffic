#include "traffic.h"

void timer_init();

uint8_t vonat = 1;
uint8_t ki = 0;
uint8_t ki_2 =0;
uint8_t nyom = 0;
uint8_t nyom_1 =0;
uint8_t gomb_1 = 0;
uint8_t gomb_2 = 0;

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
			else if(allapot == 'P')
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
			else if(allapot == 'P')
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

uint8_t panel_gomb()
{
	PORTE |= (1<<BTNV1) | (1<<BTNV2);
	
	if(BTNV1_PRESSED() && (nyom_1 == 0))
	{
		nyom_1 = 1;
		if(gomb_1 ==0 && gomb_2 == 0)
		{
			ki = 1;
			gomb_1 = 1;
			gomb_2 = 0;
		}
		if(gomb_1 == 0 && gomb_2 == 1)
		{
			ki ^=1;
			gomb_1^=1;
			gomb_2^=1;
			
			if(ki == 0)
			{
				gomb_1=gomb_2=0;
			}
		}
	}
	if(BTNV2_PRESSED() && (nyom_1 == 0))
	{
		nyom_1 = 1;
		if(gomb_1 ==0 && gomb_2 == 0)
		{
			ki = 1;
			gomb_1 = 0;
			gomb_2 = 1;
		}
		if(gomb_1 == 1 && gomb_2 == 0)
		{
			ki^=1;
			gomb_1^=1;
			gomb_2^=1;
			if(ki == 0)
			{
				gomb_1=gomb_2=0;
			}
		}
	}
	if(!BTNV1_PRESSED() && !BTNV2_PRESSED())
	{
		nyom_1 = 0;
	}
	
	return ki;
}

uint8_t gomb ()
{
	uint8_t btn = PING&0x1F;
	if(btn == 1 && nyom == 0)
	{
		nyom = 1;
		ki_2 ^= 1;
	}
	else
	{
		nyom = 0;
	}
	return ki_2;
}

void led (uint8_t led)
{
	PORTD = led;
	PORTB = led<<4;
}