#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) 
{
	int x;
	int y;
	int count;
	
	for(count=0;count<=10;count++)
	{
		for(x=0;x<count;x++)
		{
			printf("*");
		}
		for(y=0;y<(10-x);y++)
		{
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}
