#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void)
{
	char product;
	double total;
	int count;
	
	count=0;
	total=0;
	
	printf("enter the product number\n");
	scanf("%c",product);
	
	while(count<7)
	{
		switch(product)
		{
			case'1':
		    	printf("1\t\t$2.98\n");
			    total=total+2.98;
		    	break;
		    case'2':
			    printf("2\t\t$4.98\n");
				total=total+4.98;
				break;
			case'3':		
	            printf("3\t\t$9.98\n");
	            total=total+9.98;
	            break;
	        case'4':
			    printf("4\t\t$4.49\n");
				total=total+4.49;
				break;
			case'5':
			    printf("5\t\t$6.87\n");
				total=total+6.87;
				break;	 
    	}
    	
    	count++;
    	scanf("%d",&product);
	}
	
	printf("this week %d products were sold\n\nthe total products sold were worth $%.2f\n",count,total);
	
	return 0;
}
