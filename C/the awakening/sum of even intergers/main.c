#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) 
{
	int count;
	int total;
	
	total=0;
	
	for(count=0;count<=30;count++)
	{
		printf("%d ",count);
		
		if((count%2)==0)
		{
			total=total+count;
		}
		else
		{
			continue;
		}
	}
	
	printf("\n");
	
	printf("the sum is %d",total);
	
	return 0;
}
