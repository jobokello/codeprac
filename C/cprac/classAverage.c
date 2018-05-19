#include <stdio.h>
#include <stdlib.h>

void main()
{
	int x,i,count,sum;
	double average;
	sum=0;
	count=0;//initializes the count
	printf("how many marks would you like to enter?\n");//allows the user to decide the number of marks to enter
	scanf("%d",&x);
	
	
	while (count<x)
	{
        printf("please enter a mark:\n");
      	scanf("%d",&i);
	    sum=sum+i;
	    count++;//is the same as count=count+1	
	}

	average=(double)sum/count;
	printf("the average is %f",average);
}
