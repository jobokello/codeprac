/*this is a program that asks a user to enter three numbers 
then it adds them up an prints the result on the screen.
written by Okello Job Opiyo
reg no: p15/37353/2016*/
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int a,b,c,sum;
	printf("enter three numbers a,b,c\n");
	scanf("%d%d%d",&a,&b,&c);
	
	sum=a+b+c;
	printf("the sum of the numbers is %d",sum);
}
