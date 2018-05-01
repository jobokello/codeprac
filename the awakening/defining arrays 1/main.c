#include <stdio.h>
#include <stdlib.h>

void main()
{
	int n[10];
	int i;
	
	for(i=0;i<10;i++)
	{
		n[i]=i;
	}
	
	printf("%s%13s\n","element","value");
	
	for(i=0;i<10;i++)
	{
		printf("%7d%13d\n",i,n[i]);
	}
}
