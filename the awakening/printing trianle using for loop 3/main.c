#include <stdio.h>
#include <stdlib.h>

void main()
{
	int line;
	int count;
	int space;
	
	for(line=10;line>0;line--)
	{
		for (space=0;space<line;space++)
		{
			printf(" ");
		}
		
		for (count=0;count<(10-line);count++)
		{
			printf("*");
		}
		
		printf("\n");
	}
}
