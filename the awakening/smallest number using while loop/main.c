#include <stdio.h>
#include <stdlib.h>

void main()
{
	int num;
	int count;
	int min;
	count=0;
	
	printf("please enter a number:\n");
	scanf("%d",&min);
	
	while (count<10)
	{
		printf("please enter a number:\n");
		scanf("%d",&num);
		if (num<min)
		{
			min=num;
		}
		else if (min<num)
		{
			min=min;
		}
		count++;
    }
    
    printf("smallest number is %d",min);
    
}

