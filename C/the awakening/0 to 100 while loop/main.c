#include <stdio.h>
#include <stdlib.h>

void main()
{
	int x, n=-1, num[10000], c, a[10000], d;

	do
	{
		printf("Input number:\n");
		scanf_s("%d", &x);

		if (x > 100) 
		{
			printf("Skipping the value\n");
			continue; 
		}
		printf("You enterd: %d\n\n", x);

		if (x<0) 
		{
			printf("Error!\n\n");
			break;
		}

		n++;//increases the value of n by +1 so as to assign a memory location for every number entered
		num[n] = x;

	} while (x!=0);

	printf("\nYou entered the following numbers:\n");
	for (c=0;c<n;c++) 
	{
		printf("%d ", num[c]);
	}

	for (d=0;d<n;d++) 
	{
		a[d]=1;

		for (c=0;c<n;c++) 
		{
			if (num[d]==num[c]) 
			{
				a[d]++;//increases the frequency of any number entered
			}
		}

	}
	printf("\n\nBelow is a summary of the data you have entered:\n");

	for (c = 0;c<n;c++) 
	{
		printf("You entered %d\t%d times\n ", num[c],  a[c] - 1);
	}

}
