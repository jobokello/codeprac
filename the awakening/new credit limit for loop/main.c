#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) 
{
	int account;
	int oldlimit;
	int currentbalance;
	double newlimit;
	int count=0;
	
	printf("account number(EOF to end):");
	scanf("%d",&account);
	
	while(account!=EOF)
	{
		printf("old credit limit:");
		scanf("%d",&oldlimit);
		printf("current balance:");
		scanf("%d",&currentbalance);
		
		newlimit=(double)oldlimit/2;
		
		if(newlimit>currentbalance)
		{
			printf("this customer has exceeded the allowed credit limit!!!\n");
		}
		else
		{
			printf("the customer is still within the allowed credit limit!!!\n");
		}
		
		count++;
		
		printf("\n\n\n");
	}
	
	printf("total entries are %d",count);
	
	return 0;
}
