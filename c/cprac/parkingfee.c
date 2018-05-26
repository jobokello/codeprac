#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double calculaterCharges(int hr);

int main(void) 
{
	int hours;
	double charges;
	double totalCharges;
	int totalHours;
	int count;
	
	totalCharges=0;
	totalHours=0;
	count=0;
	
	printf("enter the parking hours for each car (-1 to end)\n");
	scanf("%d",&hours);
	printf("\t\tcar no.\t\thours parked\t  charges\n");
	
	while(hours!=-1)
	{
		charges=calculaterCharges(hours);
		count++;
		printf("\t\t%d\t\t%d\t\t%8.2lf\n",count,hours,charges);
		totalCharges=totalCharges+charges;
		totalHours=totalHours+hours;
		scanf("%d",&hours);
	}
	
	printf("\t\t%s\t\t%d\t\t%8.2f\n","Total",totalHours,totalCharges);
	return 0;
}

double calculaterCharges(int hr)
{
	double pay;
	
	if(hr<=2)
	{
		pay=hr*2.00;
	}
	else if(hr>2)
	{
		pay=(double)((2*2.00)+((hr-2)*0.50));
	}
	
	return pay;
}
