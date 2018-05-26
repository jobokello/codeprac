//mileage simulation program
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int tankfuls;
	int gallons;
	int miles;
	float sum;
	float mpgln;
	float average;
	
	tankfuls=0;
	sum=0;
	
	printf("please enter the miles driven(-1 to end):\n");
	scanf("%d",&miles);
	printf("please enter the gallons used(-1 to end):\n");
	scanf("%d",&gallons);
	
	while ((miles!=-1)&&(gallons!=-1))
	
	{
		mpgln=(float)miles/gallons;
		printf("the miles driven per gallon is:%f\n\n\n",mpgln);
		
		sum=sum+mpgln;
		tankfuls++;
		
	    printf("please enter the miles driven(-1 to end):\n");
	    scanf("%d",&miles);
	    printf("please enter the gallons used(-1 to end):\n");
	    scanf("%d",&gallons);
		
		
	}
	
	if (tankfuls>0)
	{
		average=(float)sum/tankfuls;
		
		printf("the average miles travelled per gallon is: %f\n",average);
	}
	
	else if (tankfuls<1)
	{
		printf("No records were entered!!!\n");
	}
	
	
}
