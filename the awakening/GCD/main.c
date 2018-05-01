#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long hcf(long x,long y);

int main(void) 
{
	long a;
	long b;
	
	printf("enter two numbers\n");
	scanf("%d%d",&a,&b);
	
	printf("the GCD is %d",hcf(a,b));
	
	return 0;
}

long hcf(long x,long y)
{
	long gcd;
	
	if(x==0)
	{
		gcd=y;
	}
	
		while(y!=0)
		{
			if(x>y)
			{
				x=x-y;
			}
			
			else if(x<y)
			{
				y=y-x;
			}
		}
		
	
	gcd=x;
	return gcd;
}
