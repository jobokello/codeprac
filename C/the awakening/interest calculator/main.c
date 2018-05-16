#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void)
{
	int principal;
	int rate;
	int time;
	float interest;
	
	printf("enter loan principal (-1 to end):");
	scanf("%d",principal);
	
	while (principal!=-1)
	{
		printf("enter rate:");
		scanf("%d",&rate);
		printf("enter time(no. of days):");
		scanf("%d",&time);	
		interest=(double)principal*rate*(time/365);
		printf("the interest is %.2f shillings.\n\n");
		printf("enter loan principal (-1 to end):");
		scanf("%d",&principal);
	}
	
	printf("DONE!!!\n");
	return 0;
}
