#include <stdio.h>
#include <stdlib.h>

void main()
{
	int a,b,c,d,e;
	
	printf("please enter five numbers:\n");
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	
	printf("number\tsquare\tcube\n");
	printf("%d\t%d\t%d\n",a,a*a,a*a*a);
	printf("%d\t%d\t%d\n",b,b*b,b*b*b);
	printf("%d\t%d\t%d\n",c,c*c,c*c*c);
	printf("%d\t%d\t%d\n",d,d*d,d*d*d);
	printf("%d\t%d\t%d\n",e,e*e,e*e*e);
	
	
}
