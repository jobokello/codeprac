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
	int multNum[1000];
	int number;
	int onedig;
	int size;
	int i,j;

	printf("size of number: ");
	scanf("%d", &size);
	printf("enter %d digits: ",size);
	scanf("%d",&number);

	for(j = size; j > 0; j--)
	{
		onedig =number - (number%(power(10,(j-1))));
		printf("%d\n",onedig);
		multNum[size - j] = onedig/(power(10,(j-1)));
		number = number - onedig;
	}

	printf("the array is: [");

	for (int i = 0; i < size; ++i)
	{
		printf(" %d",multNum[i]);
	}

	printf("]\n");


	return 0;
}