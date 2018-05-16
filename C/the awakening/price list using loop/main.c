#include <stdio.h>
#include <stdlib.h>

void main()
{
	int serial;
	int price1;
	int price2;
	int price3;
	int price4;
	int price5;
	int count;
	count=0;
	price1=4564;
	price2=3457;
	price3=5560;
	price4=2345;
	price5=5858;
	printf("Adhis shop price list\n");
	printf("enter product serial(-1 to end):\n");
	printf("product\tprice\n");
	
	while (serial!=-1)
	{
		scanf("%d",&serial);
		switch (serial)
		{
			case 1:
				printf("\t%d\n",price1);
				break;
		    case 2:
			    printf("\t%d\n",price2);
				break;
			case 3:
			    printf("\t%d\n",price3);
				break;
			case 4:
			    printf("\t%d\n",price4);
				break;
			case 5:
			    printf("\t%d\n",price5);
				break;
			default:
				printf("\product does not exist!!!!");
				break;		 	 			
		}
		
		count++;
	}
	printf("end of request!!!\n");
}
