/*this is a program that ask a user to enter a number.
if the number is equal to -1 then the program will exit
the loop and get the sum of the numbers,which will be zero.
if the number is not equal to -1 then the program will execute
the body of the while loop and when -1 finally appears the 
program will exit the loop and then get average of the numbers
 entered*/
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i,n,sum;
	double average;
	sum=0;
	i=0;
	
	printf("enter a number(-1 to end)\n");
	scanf("%d",&n);
	
	while (n!=-1)
	{
		sum=sum+n;
		printf("enter a number\n");
		scanf("%d",&n);
		i++;
	}
	
	if (i>0)
	{
		average=(double)sum/i;
		printf("the average is %.6lf\n",average);
	}
	
	else
	{
		printf("sum is %d\n",sum);
	}
}
