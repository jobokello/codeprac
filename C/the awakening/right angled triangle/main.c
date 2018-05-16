#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void)
{
	int a;
	int b;
	int c;
	
	printf("enter three sides of a triangle\n");
	scanf("%d%d%d",&a,&b,&c);
	
	if ((a*a==b*b+c*c)||(b*b==c*c+a*a)||(c*c==b*b+a*a))
	{
		printf("the three lengths are part of a right angled triangled!!!\n");
	}
	else
	{
	   printf("the three lengths are not part of a right angled triangled!!!\n"); 	
	}
	return 0;
}
