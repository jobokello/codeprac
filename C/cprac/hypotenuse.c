#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <math.h>


double hypotenuse(int x,int y)
{
	int hypo;
	
	return hypo = sqrt(pow(x,2)+pow(y,2));
}

int main(void)
{
	int x,y;
	double hyp;

	printf("enter the two sides of the triangle\n");

	scanf("%d%d",&x,&y);
	
	printf("the hypotenuse of the triangle is %f", hypotenuse(x,y));
	return 0;
}
