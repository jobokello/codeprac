#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    int c[100], i=0, j=0;
    printf("Enter 15 characters\n");

	for(j=0;j<15;j++)
    {	
    	c[j]=getc(stdin);	
    }

    for(i=0;i<15;i++)
    {
        if(isdigit(c[i]))
		{
            printf("\n\n");
            putchar(c[i]);
        	printf(" is a digit\n");
        }
        
        else if(isalpha(c[i]))
		{
            printf("\n\n");
            putchar(c[i]);
            printf(" is an alphabet\n");
        }
        
		else if
		{
            printf("\n\n");
            putchar(c[i]);
            printf(" is a special character\n");
        }

    }
    
}
