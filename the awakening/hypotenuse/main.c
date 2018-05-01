#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double hyp(double x,double y);

int main(void)
{
	double length;
	double height;
	double hypotenuse;
	
	printf("enter the length and the height\n");
	scanf("%lf%lf",&length,&height);
	printf("the hupotenuse is %.2fcm",hyp(length,height));
	return 0;
}

double hyp(double x,double y)
{
	return sqrt(pow(x,2)+pow(y,2));
}
