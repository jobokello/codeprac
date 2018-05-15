#include <stdio.h>
#include <stdlib.h>

void main()
{
	int num;
	int count;
	int max;
	count=0;
	max=0;
	
	
	while (count<10)
	{
		printf("please enter a number:\n");
		scanf("%d",&num);
		if (num>max)
		{
			max=num;
		}
		else if (max>num)
		{
			max=max;
		}
		count++;
    }
    
    printf("largest is %d",max);
    
}
