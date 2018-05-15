#include <stdio.h>
#include <stdlib.h>

void main()
{
	int x;
	int count;
	x=0;
	count=0;
	printf("x   x*10   x*100\n");
	while (count<20)
	{
		x=x+1;
	    printf("%d   %d   %d\n",x,x*10,x*100);
		count++;
    }
    
}
