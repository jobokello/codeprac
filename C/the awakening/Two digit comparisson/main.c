/*This is a program that compares two numbers
and decides whic is larger or if they are equal
written by Okello Job Opiyo
reg no:p15/37353/2016
date: 14/10/2015*/
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int a,b;
	printf("enter a number a\n");
	scanf("%d",&a);
	printf("enter a number b\n");
	scanf("%d",&b);
	
	if (a>b)
	{
		printf("%d is larger!\n",a);
	}
	else if(b>a)
	{
		printf("%d is larger!\n",b);
	}
	else
	{
		printf("the two numbers are equal!\n");
	}
}
