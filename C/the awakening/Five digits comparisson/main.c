/*This is a program that compares five numbers
and decides gets the largest ,smallest and if 
the numbers are equal.
written by Okello Job Opiyo
reg no: p15/37353/2015*/
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int a,b,c,d,e;
	printf("enter five numbers a,b,c,d,e\n");
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	
	if ((a>b)&&(a>c)&&(a>d)&&(a>e))
	{
		printf("%d is the largest\n",a);
	}
	else if ((b>a)&&(b>c)&&(b>d)&&(b>e))
	{
		printf("%d is largest\n",b);
	}
	else if ((c>a)&&(c>b)&&(c>d)&&(c>e))
	{
		printf("%d is largest\n",c);
	}
	else if ((d>a)&&(d>b)&&(d>c)&&(d>e))
	{
		printf("%d is the largerst\n");
	}
	else if ((e>a)&&(e>b)&&(e>c)&&(e>d))
	{
		printf("%d is the largest\n",e);
	}
	
		if ((a<b)&&(a<c)&&(a<d)&&(a<e))
	{
		printf("%d is the smallest\n",a);
	}
	else if ((b<a)&&(b<c)&&(b<d)&&(b<e))
	{
		printf("%d is smallest\n",b);
	}
	else if ((c<a)&&(c<b)&&(c<d)&&(c<e))
	{
		printf("%d is smallest\n",c);
	}
	else if ((d<a)&&(d<b)&&(d<c)&&(d<e))
	{
		printf("%d is the smallest\n");
	}
	else if ((e<a)&&(e<b)&&(e<c)&&(e<d))
	{
		printf("%d is the smallest\n",e);
	}
	
	else
	{
		printf("the numbers are all equal!\n");
	}
}
