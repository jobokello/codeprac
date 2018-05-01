#include <stdio.h>
#include <stdlib.h>

void main()
{
	int a,b,c,d,sum;
	double average;
	
	printf("enter numbers a,b,c,d\n");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	
	sum=a+b+c+d;
	average=(double)sum/4;
	printf("sum is %d\naverage is %f",sum,average);
	
}
