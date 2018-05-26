#include <stdio.h>
#include <stdlib.h>

int parkcharges(int hrs);

int main(void)
{
	int hours;
	int charges;
	int car_number;
	
	printf("Enter the number of hours you packed your vehicle:\n");
	printf("car_number\thours\tcharges\n");
	for(car_number=0;car_number<6;car_number++)
	{
	    scanf("%d",&hours);
	    printf("\t%d\t%d\t%d\n",car_number,hours,parkcharges(hours));
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
