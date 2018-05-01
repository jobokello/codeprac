#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	int miles;
	int gallons;
	float miles_per_gallon;
	float total_miles_per_gallon;
	int count;
	
	total_miles_per_gallon=0;
	count=0;
	
	printf("enter miles driven(-1 to end):\n");
	scanf("%d",&miles);
	printf("enter gallons consumed9(-1 to end):\n");
	scanf("%d",&gallons);
	
	while(gallons!=-1)
	{
		miles_per_gallon=(double)miles/gallons;
		printf("the miles/gallons for this tank is %.6f\n\n\n",miles_per_gallon);
		total_miles_per_gallon=total_miles_per_gallon+miles_per_gallon;
		count++;
		
		printf("enter miles driven(-1 to end):\n");
    	scanf("%d",&miles);
	    printf("enter gallons consumed9(-1 to end):\n");
	    scanf("%d",&gallons);
	}
	
	printf("the average miles per gallons used is%.6f!!!\n",(double)total_miles_per_gallon/count);
	return 0;
}
