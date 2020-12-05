#include "traffic.h"

#define F_CPU 16000000
#include <util/delay.h>

void program();
void train_come();

int main(void)
{
	init();
	sec_cntr = 0;
	cntr_en = 1;
	delta_cntr = 0;
	cntr_delta_en = 0;
	
    while (1) 
    {
		led(sec_cntr);
		uint8_t vonat_gomb = panel_gomb();
		uint8_t szerviz = gomb();
		if(szerviz == 1)
		{
			sec_cntr = 0;
			kapcsol(1,0); kapcsol(2,0); kapcsol(3,0); kapcsol(4,0); kapcsol(5,0); kapcsol(6,0); kapcsol(7,0); kapcsol(8,0); kapcsol(9,0);
			PWM_villog('S');
			if(vonat_gomb == 1)
			{
				kapcsol('V', 'P');
			}
			else
			{
				kapcsol('V', 'F');
			}
		}
		else
		{
			PWM_villog(0);
			if(vonat_gomb == 1)
			{
				train_come();
			}
			else
			{
				program();
			}
		}
		
		
    }
}

void program()
{
		if (cntr_en == 0)
		{
			cntr_delta_en = 1;
			cntr_en = 0;
			switch(delta_cntr)
			{
				case 1:
				kapcsol(1,'P'); kapcsol(2,'P'); kapcsol(3,'P'); kapcsol(4,'S'); kapcsol(5,'S'); kapcsol(6,'P'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'S'); kapcsol('V','P');
				break;
				
				case 2:
				kapcsol(1,'P'); kapcsol(2,'N'); kapcsol(3,'P'); kapcsol(4,'P'); kapcsol(5,'P'); kapcsol(6,'P'); kapcsol(7,'N'); kapcsol(8,'P'); kapcsol(9,'S'); kapcsol('V','P');
				break;
				
				case 3:
				kapcsol('V','F');
				sec_cntr = 2;
				cntr_en =1;
				break;
				
				default:
				break;
			}
			
		}
		else
		{
			switch(sec_cntr)
			{
				
				
				
				case 0:
				kapcsol(1,'P'); kapcsol(2,'P'); kapcsol(3,'P'); kapcsol(4,'P'); kapcsol(5,'P'); kapcsol(6,'P'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'P'); //piros
				break;
				
				case 1:
				kapcsol(1,'P'); kapcsol(2,'N'); kapcsol(3,'P'); kapcsol(4,'P'); kapcsol(5,'P'); kapcsol(6,'N'); kapcsol(7,'N'); kapcsol(8,'P'); kapcsol(9,'P'); //2,7
				break;
				
				//1. Allapot
				
				case 2:
				kapcsol(1,'Z'); kapcsol(2,'Z'); kapcsol(3,'P'); kapcsol(4,'P'); kapcsol(5,'P'); kapcsol(6,'P'); kapcsol(7,'Z'); kapcsol(8,'Z'); kapcsol(9,'P'); //1*,2,7,8
				break;
				
				
				
				case 7:
				kapcsol(1,'P'); kapcsol(2,'S'); kapcsol(3,'P'); kapcsol(4,'P'); kapcsol(5,'P'); kapcsol(6,'P'); kapcsol(7,'S'); kapcsol(8,'S'); kapcsol(9,'P'); //1,2,7,8
				break;
				
				case 8:
				kapcsol(1,'P'); kapcsol(2,'S'); kapcsol(3,'N'); kapcsol(4,'P'); kapcsol(5,'P'); kapcsol(6,'P'); kapcsol(7,'S'); kapcsol(8,'S'); kapcsol(9,'P'); //2,7,8  3
				break;
				
				//2. Allapot
				
				case 9:
				kapcsol(1,'P'); kapcsol(2,'P'); kapcsol(3,'Z'); kapcsol(4,'P'); kapcsol(5,'P'); kapcsol(6,'Z'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'P'); //6*,3
				break;
				
				
				
				case 14:
				kapcsol(1,'P'); kapcsol(2,'P'); kapcsol(3,'S'); kapcsol(4,'P'); kapcsol(5,'P'); kapcsol(6,'P'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'P'); //3
				break;
				
				case 15:
				kapcsol(1,'P'); kapcsol(2,'P'); kapcsol(3,'S'); kapcsol(4,'N'); kapcsol(5,'N'); kapcsol(6,'P'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'P'); //3 4,5
				break;
				
				//3. Allapot
				
				case 16:
				kapcsol(1,'P'); kapcsol(2,'P'); kapcsol(3,'P'); kapcsol(4,'Z'); kapcsol(5,'Z'); kapcsol(6,'Z'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'Z');// 4,5,6,9
				break;
				
				
				
				case 21:
				kapcsol(1,'P'); kapcsol(2,'P'); kapcsol(3,'P'); kapcsol(4,'S'); kapcsol(5,'S'); kapcsol(6,'P'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'S'); //4,5,9
				break;
				
				case 22:
				kapcsol(1,'P'); kapcsol(2,'N'); kapcsol(3,'P'); kapcsol(4,'S'); kapcsol(5,'S'); kapcsol(6,'S'); kapcsol(7,'N'); kapcsol(8,'P'); kapcsol(9,'S'); //4,5,9 2,7
				break;
				
				case 23:
				sec_cntr = 2;
				break;
				
				default:
				break;
			}
		}	
}

void train_come()
{
	if((sec_cntr<2) && (sec_cntr>=0))
	{
		if(cntr_en == 1)
		{
			delta_cntr = 0;
			cntr_delta_en = 1;
		}
		cntr_en = 0;
		
		switch (delta_cntr)
		{
			case 1:
			kapcsol(1,'P'); kapcsol(2,'P'); kapcsol(3,'P'); kapcsol(4,'P'); kapcsol(5,'P'); kapcsol(6,'P'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'P'); //1*,2,7,8
			break;
			
			case 2:
			kapcsol(1,'P'); kapcsol(2,'P'); kapcsol(3,'P'); kapcsol(4,'N'); kapcsol(5,'N'); kapcsol(6,'P'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'P'); //1*,2,7,8
			break;
			
			case 3:
			kapcsol(1,'Z'); kapcsol(2,'P'); kapcsol(3,'P'); kapcsol(4,'Z'); kapcsol(5,'Z'); kapcsol(6,'P'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'Z'); kapcsol('V','P'); //1*,2,7,8
			cntr_delta_en = 0;
			delta_cntr = 0;
			break;
			
			default:
			break;
		}
	}
	
	if((sec_cntr<7) && (sec_cntr>=2))
	{
		if(cntr_en == 1)
		{
			delta_cntr = 0;
			cntr_delta_en = 1;
		}
		cntr_en = 0;
		
		switch (delta_cntr)
		{
			case 1:
			kapcsol(1,'Z'); kapcsol(2,'S'); kapcsol(3,'P'); kapcsol(4,'P'); kapcsol(5,'P'); kapcsol(6,'P'); kapcsol(7,'S'); kapcsol(8,'S'); kapcsol(9,'P'); //1*,2,7,8
			break;
			
			case 2:
			kapcsol(1,'Z'); kapcsol(2,'S'); kapcsol(3,'P'); kapcsol(4,'N'); kapcsol(5,'N'); kapcsol(6,'P'); kapcsol(7,'S'); kapcsol(8,'S'); kapcsol(9,'N'); //1*,2,7,8
			break;
			
			case 3:
			kapcsol(1,'Z'); kapcsol(2,'P'); kapcsol(3,'P'); kapcsol(4,'Z'); kapcsol(5,'Z'); kapcsol(6,'P'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'Z'); kapcsol('V','P'); //1*,2,7,8
			cntr_delta_en = 0;
			delta_cntr = 0;
			break;
			
			default:
			break;
		}
	}
	
	if((sec_cntr<9) && (sec_cntr>=7))
	{
		if(cntr_en == 1)
		{
			delta_cntr = 0;
			cntr_delta_en = 1;
		}
		cntr_en = 0;
		
		switch (delta_cntr)
		{
			case 1:
			kapcsol(1,'P'); kapcsol(2,'S'); kapcsol(3,'P'); kapcsol(4,'P'); kapcsol(5,'P'); kapcsol(6,'P'); kapcsol(7,'S'); kapcsol(8,'S'); kapcsol(9,'P'); //1,2,7,8
			break;
			
			case 2:
			kapcsol(1,'P'); kapcsol(2,'S'); kapcsol(3,'P'); kapcsol(4,'N'); kapcsol(5,'N'); kapcsol(6,'P'); kapcsol(7,'S'); kapcsol(8,'S'); kapcsol(9,'P'); //1*,2,7,8
			break;
			
			case 3:
			kapcsol(1,'Z'); kapcsol(2,'P'); kapcsol(3,'P'); kapcsol(4,'Z'); kapcsol(5,'Z'); kapcsol(6,'P'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'Z'); kapcsol('V','P'); 
			cntr_delta_en = 0;
			delta_cntr = 0;
			break;
			
			default:
			break;
		}
	}
	
	if((sec_cntr<14) && (sec_cntr>=9))
	{
		if(cntr_en == 1)
		{
			delta_cntr = 0;
			cntr_delta_en = 1;
		}
		cntr_en = 0;
		
		switch (delta_cntr)
		{
			case 1:
			kapcsol(1,'P'); kapcsol(2,'P'); kapcsol(3,'S'); kapcsol(4,'P'); kapcsol(5,'P'); kapcsol(6,'S'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'P'); //6*,3
			break;
			
			case 2:
			kapcsol(1,'P'); kapcsol(2,'P'); kapcsol(3,'S'); kapcsol(4,'N'); kapcsol(5,'N'); kapcsol(6,'S'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'P'); //1*,2,7,8
			break;
			
			case 3:
			kapcsol(1,'Z'); kapcsol(2,'P'); kapcsol(3,'P'); kapcsol(4,'Z'); kapcsol(5,'Z'); kapcsol(6,'P'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'Z'); kapcsol('V','P');
			cntr_delta_en = 0;
			delta_cntr = 0;
			break;
			
			default:
			break;
		}
	}
	
	if((sec_cntr<16) && (sec_cntr>=14))
	{
		if(cntr_en == 1)
		{
			delta_cntr = 0;
			cntr_delta_en = 1;
		}
		cntr_en = 0;
		
		switch (delta_cntr)
		{
			case 1:
			kapcsol(1,'P'); kapcsol(2,'P'); kapcsol(3,'S'); kapcsol(4,'P'); kapcsol(5,'P'); kapcsol(6,'P'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'P'); //3
			break;
			
			case 2:
			kapcsol(1,'P'); kapcsol(2,'S'); kapcsol(3,'S'); kapcsol(4,'N'); kapcsol(5,'N'); kapcsol(6,'P'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'P'); //1*,2,7,8
			break;
			
			case 3:
			kapcsol(1,'Z'); kapcsol(2,'P'); kapcsol(3,'P'); kapcsol(4,'Z'); kapcsol(5,'Z'); kapcsol(6,'P'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'Z'); kapcsol('V','P');
			cntr_delta_en = 0;
			delta_cntr = 0;
			break;
			
			default:
			break;
		}
	}
	
	if((sec_cntr<=22) && (sec_cntr>=16))
	{
		if(cntr_en == 1)
		{
			delta_cntr = 0;
			cntr_delta_en = 1;
		}
		cntr_en = 0;
		
		switch (delta_cntr)
		{
			case 1:
			kapcsol(1,'P'); kapcsol(2,'P'); kapcsol(3,'P'); kapcsol(4,'Z'); kapcsol(5,'Z'); kapcsol(6,'Z'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'Z');// 4,5,6,9
			break;
			
			case 2:
			kapcsol(1,'P'); kapcsol(2,'P'); kapcsol(3,'P'); kapcsol(4,'Z'); kapcsol(5,'Z'); kapcsol(6,'S'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'Z'); //1*,2,7,8
			break;
			
			case 3:
			kapcsol(1,'Z'); kapcsol(2,'P'); kapcsol(3,'P'); kapcsol(4,'Z'); kapcsol(5,'Z'); kapcsol(6,'P'); kapcsol(7,'P'); kapcsol(8,'P'); kapcsol(9,'Z'); kapcsol('V','P');
			cntr_delta_en = 0;
			delta_cntr = 0;
			break;
			
			default:
			break;
		}
	}
}