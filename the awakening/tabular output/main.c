#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int count;
	count=1;
	printf("N\tN*10\tN*100\tN*1000\n");
	while(count<=20)
	{
		printf("%d\t%d\t%d\t%d\n",count,10*count,100*count,1000*count);
		count++;
	}
	return 0;
}
