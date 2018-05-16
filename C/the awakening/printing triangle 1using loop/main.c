#include <stdio.h>
#include <stdlib.h>

void main()
{
	int count;
	int line;
	count=0;
	line=0;
	
	
	for (line=0;line<10;line++)
	{
		
		for (count=0;count<line;count++)
		{
			printf("*");
		}
		
		printf("\n");
	}
}
