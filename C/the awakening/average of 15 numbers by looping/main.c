#include <stdio.h>
#include <stdlib.h>

void main()
{
	int num;
	int sum;
	int count;
	double average;
	sum=0;
	
	for (count=1;count<=15;count++)
	{
		printf("enter a number:\n");
		scanf("%d",&num);
		
		sum=sum+num;
		average=(double)sum/count;
		
		printf("sum is %d\naverage is %lf\n",sum,average);
	}
	
	printf("final sum is %d\nfinal average is %lf",sum,average);
}
