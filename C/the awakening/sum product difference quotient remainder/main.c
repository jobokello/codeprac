#include <stdio.h>
#include <stdlib.h>

void main()
{
	int x,y;
	int sum;
	int difference;
	double product;
	double quotient;
	double remainder;
	
	printf("please enter two integers\n");
	scanf("%d%d",&x,&y);
	
	sum=x+y;
	difference=x-y;
	product=x*y;
	quotient=x/y;
	remainder=x%y;
	
	printf("sum is %d\ndifference is %d\nproduct is %.12lf\nquotient is %.12f\nremainder is %.12lf\n",sum,difference,product,quotient,remainder);
}
