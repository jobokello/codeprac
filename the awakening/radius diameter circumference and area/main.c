#include <stdio.h>
#include <stdlib.h>

void main()
{
	int x;
	double diameter;
	double circumference;
	double area;
	
	printf("please enter the radius of the circle\n");
	scanf("%d",&x);
	
	printf("raius is %dcm\ndiameter is %dcm\ncircumference is %fcm\narea is %fcm squared\n",x,2*x,2*3.142*x,3.142*x*x);
}



