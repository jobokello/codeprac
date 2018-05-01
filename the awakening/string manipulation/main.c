#include<stdio.h>

void main()
{
	char string[20];
	char*word;
	printf("please enter a string\n");
	gets(string);
	word=strtok(string," ");
	
	while (word!=NULL)
	{
		printf("%s\n",word);
		word=strtok(NULL," ");
	}
}
