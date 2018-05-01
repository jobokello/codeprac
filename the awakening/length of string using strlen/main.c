#include <stdio.h>
#include <stdlib.h>

void main()
{
	char string[50];
	
	printf("please enter a string:\n");
	scanf("%s",&string);
	printf("the length of the string is %d.\n",strlen(string));
}
