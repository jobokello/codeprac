#include <stdio.h>
#include <stdlib.h>

void main()
{
	int account;
	int balance;
	int charges;
	int credit;
	int limit;
	int final;
	int count;
	
	count=0;
	
	printf("enter account number(-1 to end):\n");
	scanf("%d",&account);
	printf("enter beginning balance:\n");
	scanf("%d",&balance);
	printf("enter items charged:\n");
	scanf("%d",&charges);
	printf("enter credit applied:\n");
	scanf("%d",&credit);
	printf("enter credit limit\n");
	scanf("%d",&limit);
	printf("\n\n");
	final=balance+charges-credit;
	
	if (final>limit)
	{
		printf("the account number %d has exceeded credit limit\n\n\n",account);
	}
	
	else if (final<limit)
	{
		printf("the account number %d has not exceeded credit limit\n\n\n",account);
	}
	
	while (account!=-1)
	{
	  	
    	printf("enter account number(-1 to end):\n");
        scanf("%d",&account);
        printf("enter beginning balance:\n");
	    scanf("%d",&balance);
	    printf("enter items charged:\n");
	    scanf("%d",&charges);
	    printf("enter credit applied:\n");
	    scanf("%d",&credit);
	    printf("enter credit limit\n");
	    scanf("%d",&limit);
	    printf("\n\n");
	    
	 
	    final=balance+charges-credit;
	
	    if (final>limit)
	    {
		    printf("the account number %d has exceeded credit limit\n\n\n",account);
	    }
	
	   else if (final<limit)
	    {
		    printf("the account number %d has not exceeded credit limit\n\n\n",account);
	    }
	    
	    count++;
	}
	
	if (count<1)
	{
		printf("no more records were entered!!!\n");
	}
}
