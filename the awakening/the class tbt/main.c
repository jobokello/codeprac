#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	int x,i,z;
	printf("how many student marks would you like to enter?\n");
	scanf("%d",&z);
	char students[z][20];
	int geography[z];
	int english[z];
	int maths[z];
	
	for (i=0;i<z;i++)
	{
		printf("student name:\n");
		scanf("%s",students[i]);
		printf("maths marks:\n");
		scanf("%d",&maths[i]);
		printf("english marks:\n");
		scanf("%d",&english[i]);
		printf("geography marks:\n");
		scanf("%d",&geography[i]);
	}
	
	printf("students maths\tenglish\tgeography\n");
	
	for (i=0;i<z;i++)
	{
		printf("%s\t%d\t%d\t%d\n",students[i],maths[i],english[i],geography[i]);
	}
}
