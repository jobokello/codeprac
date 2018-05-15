#include <stdio.h>
#include <stdlib.h>

int packcharges(int hrs);

int main(void)
{
	int hours;
	int charges;
	int car_number;
	
	Printf("please enter the number of hours you packed your vehicle:");
	printf("car_number\thours\tcharges\n");
	for(car_number=0;car_number<3;car_number++)
	{
	    scanf("%d",&hours);
	    printf("%d\t%d\t%d",car_number,hours,packcharges(hours));
	}

	return 0;
}

int parkcharges(int hrs)
{
	if(hrs<=2)
	{
		return 200*hrs;
	}
	else
	{
		return (200*hrs)+((hrs-2)*100);
	}
	
}
