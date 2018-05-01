#include <stdio.h>
#include <stdlib.h>

void main()
{
	int number;
	int x;
	x=0;
	number=1;
	
	while (x<20)
	{
		if ((x%5)==0)
		{
			printf("\n");
		}
		
		 printf("%d ",number);
		 
		number++;
		x++;
    }
	
	
}
