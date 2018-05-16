#include <stdio.h>
#include <stdlib.h>

void main()
{
    int count;
	
	count=1;
	  
	
    while (count<101)
    {
	    printf("*");
	    
	    if ((count%10)==0)
		{
	    	printf("\n");
		}
		
		count++;	
    }
		
    
}
