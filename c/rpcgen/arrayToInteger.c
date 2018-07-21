#include <stdio.h>
#include <stdlib.h>


int power(int base, int exp)
    {
      if(exp < 0)
        return -1;

        int result = 1;
        while (exp)
        {
            if (exp & 1)
                result *= base;
            exp >>= 1;
            base *= base;
        }

        return result;
    }

int main(int argc, char const *argv[])
{
	int i, j;
	int size;
	int numbers[1000];
	int oneNumber=0;

	printf("enter size of nxn array: ");
	scanf("%d", &size);
	printf("\n");

	printf("the array is: [");

	for (i = 0; i < size; i++)
	{
		numbers[i] = i+1;
		printf(" %d", numbers[i] );
	}

	printf("]\n");

	for(j = size-1; j > -1; j--)
	{
		oneNumber = oneNumber + ((numbers[size - (j+1)]) * (power(10,j)));
	}

	printf("%d\n",oneNumber);

	//printf("%d\n",power(10,3));

	return 0;
}
