#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void)
{
	int a;
	int b;
	int c;
	
	printf("enter  three sides of a triangle\n");
	scanf("%d%d%d",&a,&b,&c);
	
	if ((a!=b)&&(a!=c)&&(b!=c))
	{
		printf("the three are valid sides of a triangle!!!\n");
	}
	else
	{
        printf("the three are not valid sides of a triangle!!!\n");	 		
	}
	return 0;
}
