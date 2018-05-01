#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) 
{
	int x;
	int y;
	int count;
	int factorial;
	
	y=15;
	  
    printf("number\tfactorial\n");
    
	for(count=1;count<=y;count++)
	{
		factorial=1;
		
		for(x=1;x<=count;x++)
		{
			factorial=factorial*x;
		}
		
		printf("%d\t%d\n",count,factorial);
	}
	return 0;
}
