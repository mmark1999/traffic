#include "traffic.h"

#define F_CPU 16000000
#include <util/delay.h>

int main(void)
{
	init();
	
    while (1) 
    {
		if(gomb() == 1)
		{
			kapcsol(2,'P');
		}
		else
		{
			kapcsol(2, 0);
		}
    }
}

