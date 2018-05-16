#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) 
{
	int number;
	int next;
	int count;
	int minimum;
	
	printf("enter a number:");
	scanf("%d",&number);
	
	minimum=number;
	
	for(count=0;count<number;count++)
	{
		scanf("%d",&next);
		
		if(next<minimum)
		{
			minimum=next;
		}
		else if(next>minimum)
		{
			minimum=minimum;
		}
	}
	
	printf("the smallest number is %d",minimum);
	
	return 0;
}
