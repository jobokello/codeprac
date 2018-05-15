#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int sales;
	int salary;
	int count;
	
	count=1;
	
	printf("%d.\tEnter sales for the week (-1 to end):",count);
	scanf("%d",&sales);
	while (sales!=-1)
	{
		salary=200+0.09*sales;
		printf("\tThe gross salary for the worker is %d\n\n",salary);
		count++;
		
		printf("%d.\tEnter sales for the week (-1 to end):",count);
		scanf("%d",&sales);
	}
	
	printf("\tAll entries done!!!\n");
	
	return 0;
}
