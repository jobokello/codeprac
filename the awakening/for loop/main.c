#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i,n,sum;
	double average;
	sum;
	
	for(i=0;i<5;i++)
	{
		printf("enter a number n.\n");
		scanf("%d",&n);
		sum=sum+n;
	}
	
	average=(double)sum/i;
	printf("sum of the numbers is %d\n",sum);
	printf("the average of the numbers is %.6lf\n",average);
}
