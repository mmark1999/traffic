#include "traffic.h"

uint8_t PWM_cnt = 0;
uint8_t PWM_seg_cnt = 0;
uint8_t PWM = 0;
uint8_t multiply = 1;
char lamp = 0;

int it_cntr = 0;
uint8_t train = 0;

void PWM_func();
void vonat_lampa();

ISR(TIMER0_COMP_vect)
{
	if(it_cntr == 1000)
	{
		it_cntr = 0;
	}
	else
	{
		it_cntr++;
	}
	if(it_cntr == 500)
	{
		train++;
		vonat_lampa();
	}
}

ISR(TIMER2_OVF_vect)
{
	if(PWM_seg_cnt == 123)
	{
		PWM_seg_cnt = 0;
		PWM_cnt += (multiply*1);
		if(PWM_cnt == 255)
		{
			multiply = -1;
		}
		if(PWM_cnt == 0)
		{
			multiply = 1;
		}
	}
	else
	{
		PWM_seg_cnt++;
	}
	
	PWM_func();
	
	PWM++;
}

void PWM_func()
{
	if(PWM < PWM_cnt)
	{
		if(vonat == 1)
		{
			PORTF |= (1<<LV_F);
		}
		else
		{
			PORTF &= ~(1<<LV_F);
		}
		
		switch(lamp)
		{
			case 8:
			PORTE |= (1<<LG1_Z);
			break;
			
			case 9:
			PORTE |= (1<<LG2_Z);
			break;
			
			case 'S':
			PORTA |= (1<<LA_S)|(1<<LB_S);
			PORTC |= (1<<LC_S)|(1<<LD_S)|(1<<LE_S);
			break;
			
			case 0:
			break;
		}
	}
	else
	{
		if(vonat == 1)
		{
			PORTF &= ~(1<<LV_F);
		}
		else
		{
			PORTF &= ~(1<<LV_F);
		}
		
		switch(lamp)
		{
			case 8:
			PORTE &= ~(1<<LG1_Z);
			break;
			
			case 9:
			PORTE &= ~(1<<LG2_Z);
			break;
			
			case 'S':
			PORTA &= (~(1<<LA_S))&(~(1<<LB_S));
			PORTC &= (~(1<<LC_S))&(~(1<<LD_S))&(~(1<<LE_S));
			break;
			
			case 0:
			break;
		}
	}
}

void PWM_villog(char lampa)
{
	PWM_cnt = 0;
	PWM_seg_cnt = 0;
	PWM = 0;
	multiply = 1;
	lamp = lampa;
}

void vonat_lampa()
{
	if(vonat == 0)
	{
		if(train == 1)
		{
			PORTF |= (1<<LV_P1);
			PORTF &= ~(1<<LV_P2);
		}
		if (train == 2)
		{
			train = 0;
			PORTF |= (1<<LV_P2);
			PORTF &= ~(1<<LV_P1);
		}
	}
	
	if(vonat == 1)
	{
		PORTF &= ~(1<<LV_P1);
		PORTF &= ~(1<<LV_P2);
		train = 0;
	}
	
}