#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int number;
	int max;
	int count;
	max=0;
	count=0;
	
	printf("enter ten numbers\n");
	
	while(count<10)
	{
		scanf("%d",&number);
		
		if(number>max)
		{
			max=number;
		}
		else if(number<max)
		{
			max=max;
		}
		
		count++;
	}
	
	printf("the largest number is %d",max);
	return 0;
}
