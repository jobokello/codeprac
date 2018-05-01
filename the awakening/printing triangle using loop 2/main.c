#include <stdio.h>
#include <stdlib.h>

void main()
{
	int line;
	int count;
	
	for (line=10;line>0;line--)
	{
		for (count=line;count>0;count--)
		{
			printf("*");
		}
		printf("\n");
	}
}
