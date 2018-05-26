#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) 
{
	int sales;
	double total;
	int x;
	int y;
	int range[9];
	char commissions[9][20]={"200-299","300-399","400-499","500-599","600-699","700-799","800-899","900-999","1000 and above"};
	
	for(x=0;x<9;x++)
	{
		range[x]=0;
	}
	
	printf("enter employee sales for the week(-1 to end):\n");
	scanf("%d",&sales);
	
	while(sales!=-1)
	{
		total=(double)(200+(0.09*sales));
		
		if((total>=200)&&(total<=299))
		{
			++range[0];
		}
		else if((total>=300)&&(total<=399))
		{
			++range[1];
		}
		else if((total>=400)&&(total<=499))
		{
			++range[2];
		}
		else if((total>=500)&&(total<=599))
		{
			++range[3];
		}
		else if((total>=600)&&(total<=699))
		{
			++range[4];
		}
		else if((total>=700)&&(total<=799))
		{
			++range[5];
		}
		else if((total>=800)&&(total<=899))
		{
			++range[6];
		}
		else if((total>=900)&&(total<=999))
		{
			++range[7];
		}
		else if((total>=1000))
		{
			++range[8];
		}
		
		scanf("%d",&sales);
	}
	printf("range\t\temployees\n");
	
	for(y=0;y<9;y++)
	{
		printf("%s\t\t\t%d\n",commissions[y],range[y]);
	}
	
	return 0;
}
