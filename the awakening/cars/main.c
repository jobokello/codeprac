#include <stdio.h>
#include <stdlib.h>

int parkcharges(int hrs);

int main(void)
{
	int hours;
	int charges;
	int car_number;
	int totalhrs=0;
	int totalcash=0;
	
	printf("please enter the number of hours you packed your vehicle:\n");
	printf("\t\tcar_number\thours\tcharges\n");
	for(car_number=1;car_number<=10;car_number++)
	{
	    scanf("%d",&hours);
	    printf("\t\t%d\t\t%d\t%d\n",car_number,hours,parkcharges(hours));
	    totalcash=totalcash+parkcharges(hours);
	    totalhrs=totalhrs+hours;
	}
	printf("\t\tTotal\t\t%d\t%d\n",totalhrs,totalcash);

	return 0;
}

int parkcharges(int hrs)
{
	int tchg;
	
	if(hrs<=2)
	{
		tchg=200*hrs;
	}
	else
	{
		tchg=(200*hrs)+((hrs-2)*100);
	}
	
	return tchg;
	
}
