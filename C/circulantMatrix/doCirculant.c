#include <stdio.h>
#include <stdlib.h>

void doCirculant(int n)
{
	int i, j, k,l,x,y,populate = 1;
	int tempHolder;
	int matrix[n][n];
	int circulantMatrix[n][n];

	for(i=0; i<n; i++)
	{
		populate = 1;
		for(j=0; j<n; j++)
		{
			matrix[i][j] = populate;
			populate++;
		}
	}

	printf("the original matrix is:\n\n");

	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{

			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	for(i=n-1; i>-1; i--)
	{
		for(k=i; k>-1; k--)
		{
			tempHolder = matrix[i][n-1];
			for(j=n-1; j>0; j--)
			{
				matrix[i][j] = matrix[i][j-1];
				printf("[%d][%d]=[%d][%d]\t", i,j,i,j-1);
			}
			matrix[i][0] = tempHolder;
			printf("\n");
			/*for(x=0; x<n; x++)
			{
				for(y=0; y<n; y++)
				{

					printf("%d\t",matrix[x][y]);
				}
				printf("\n");
			}*/
			//printf("\n");
		}
		printf("\n\n");
	}

	printf("\nthe new matrix is:\n\n\n");

	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
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
