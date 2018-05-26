//Name	 : Okello Job Opiyo
//Reg no.: P15/37353/2016

#include <stdio.h>
#include <stdlib.h>

void doCirculant(int c)
{
	int i, j, k,l,x,y,populate = 1;
	int tempHolder;
	char matrix[c][c];
	int circulantMatrix[c][c];

	for(i=0; i<c; i++)
	{
		populate = 1;
		for(j=0; j<c; j++)
		{
			matrix[i][j] = populate;
			populate++;
		}
	}

	printf("the original matrix is:\n\n");

	for(i=0; i<c; i++)
	{
		for(j=0; j<c; j++)
		{

			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	for(i=c-1; i>-1; i--)
	{
		for(k=i; k>0; k--)
		{
			tempHolder = matrix[i][c-1];
			for(j=c-1; j>0; j--)
			{
				matrix[i][j] = matrix[i][j-1];
				printf("[%d][%d]=[%d][%d]\t", i,j,i,j-1);
			}
			matrix[i][0] = tempHolder;
			printf("\n");
		}
		printf("\n\n");
	}

	printf("\nthe new matrix is:\n\n\n");

	for(i=0; i<c; i++)
	{
		for(j=0; j<c; j++)
		{

			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}

	printf("\n\n\n");

}

int main(int argc, char const *argv[])
{
	int n;

	printf("enter the size of the nxn matrix\n");
	scanf("%d", &n);

	doCirculant(n);
	return 0;
}