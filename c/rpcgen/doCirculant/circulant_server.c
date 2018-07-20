/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "circulant.h"

int *
docirculant_1_svc(myVector *argp, struct svc_req *rqstp)
{
	static int  result;
	int matSize;
	int i,j,k,x=0;
	int tempHolder;
	int circulantMatrix[1000];
	int matrix[1000][1000];
	int myVector[1000];

	matSize = argp->vectSize;

	printf("the received vector is: [");

	for (int i = 0; i < matSize; ++i)
	{
		myVector[i] = i;
	}

   	for(i=0; i<matSize; i++)
   	{
      	printf("%d  ", myVector[i]);
   	}

   	printf("]\n");


   	printf("size = %d\nThe generated matrix is:\n", matSize);

   	for(i=0; i<matSize; i++)
   	{
      	for(j=0; j<matSize; j++)
      	{
         	matrix[i][j] = myVector[j];
         	printf("%d\t", matrix[i][j]);
      	}
      	printf("\n");
   	}

   	printf("\n\n");

   	for(i=matSize-1; i>-1; i--)
   	{
      	for(k=i; k>0; k--)
      	{
         	tempHolder = matrix[i][matSize-1];
         	for(j=matSize-1; j>0; j--)
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

   	for(i=0; i<matSize; i++)
   	{
      	for(j=0; j<matSize; j++)
      	{
         	printf("%d\t",matrix[i][j]);
         	circulantMatrix[x] = matrix[i][j];
         	x++;
      	}
      	printf("\n");
   	}

	return &result;

	exit(0);
}