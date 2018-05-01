#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i,n,sum;
	double average;
	sum=0;
	i=0;
	
	do
	{
		printf("enter a number n\n");
		scanf("%d",&n);
		sum=sum+n;
		i++;
	}
	
	while(i<5);
	average=(double)sum/i;
	printf("the sum of the numbers is %d\n",sum);
	printf("the average of the numbers is %f\n",average);
}
