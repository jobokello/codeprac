#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int perfect(int x);

int main(void) 
{
	int number;
	int decider;
	
	printf("enter a number:");
	scanf("%d",&number);
	
	decider=perfect(number);
	
	if (decider==1)
	{
		printf("the number is perfect!!!\n");
	}
	
	else if (decider==2)
	{
		printf("the number is not perfect!!!!\n");
	} 
	return 0;
}

int perfect(int x)
{
	int count;
	int result;
	int sum;
	int truth;
	
	sum=0;
	
	for (count=1;count<x;count++)
	{
		result=x%count;
		
		if (result==0)
		{
			sum=sum+count;
		}
	}
	
	if (sum==x)
	{
		truth=1;
	}
	
	else if (sum!=x)
	{
		truth=2;
	}
	
	return truth;
}
