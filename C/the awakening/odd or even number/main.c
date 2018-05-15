#include <stdio.h>
#include <stdlib.h>

void main()
{
	int x;
	
	printf("please enter a number\n");
	scanf("%d",&x);
	
	if ((x%2)==0)
	{
		printf("%d is even\n",x);
	}
	
	if ((x%2)>0)
	{
		printf("%d is odd",x);
	}
}
