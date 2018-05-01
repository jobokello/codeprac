#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void)
{
	int hours;
	int rate;
	float salary;
	
	printf("enter the hours worked(-1 to end):");
	scanf("%d",&hours);
	
	while (hours!=-1)
	{
		printf("enter rate:");
		scanf("%d",&rate);
		
		if(hours<=40)
		{
			salary=hours*rate;
		}
		else if(hours>40)
		{
			salary=(40*rate)+((hours-40)*(1.5*rate));
		}
		
		printf("the salary for the worker is: %f shillings\n\n",salary);
		printf("enter the hours worked(-1 to end):");
	    scanf("%d",&hours);		
	}
	return 0;
}
