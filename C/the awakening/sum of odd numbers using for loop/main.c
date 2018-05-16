#include <stdio.h>
#include <stdlib.h>

void main()
{
	int number;
	int count;
	int sum;
	number=0;
	sum=0;
	
	for (count=0;count<99;count++)
	{
		if (number%2==1)
		{
			sum=sum+number;
		}
		
		number++;
	}
	
	printf(" the sum is %d",sum);
}
