#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	int number;
	int total;
	int count;
	int new_number;
	
	printf("enter a number:");
	scanf("%d",&number);
	total=number;
	
	for(count=0;count<number;count++)
	{
		scanf("%d",&new_number);
		total=total+new_number;
	}
	
	printf("the total is %d",total);
	
	return 0;
}
