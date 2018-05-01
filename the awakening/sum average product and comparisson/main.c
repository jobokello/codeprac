#include <stdio.h>
#include <stdlib.h>

void main()
{
	int a,b,c;
	int sum;
	double product;
	double average;
	
	printf("please enter three integers\n");
	scanf("%d%d%d",&a,&b,&c);
	
	sum=a+b+c;
	product=a*b*c;
	average=product/3;
	
	
	
	if ((a>b)&&(a>c))
	{
	    printf("%d is the largest\n",a);	
	}
	
	
	if((b>a)&&(b>c))
	{
		printf("%d is the largest\n",b);
	}
	
	if ((c>a)&&(c>b))
	{
		printf("%d is largest\n",c);
	}
	
	
	if ((a<b)&&(a<c))
	{
	    printf("%d is the smallest\n",a);	
	}
	
	
	if((b<a)&&(b<c))
	{
		printf("%d is the smallest\n",b);
	}
	
	if ((c<a)&&(c<b))
	{
		printf("%d is smallest\n",c);
	}
	
	printf("sum is %d\nproduct is %f\naverage is %f\n",sum,product,average);
	
}
