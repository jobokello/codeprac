/*this is a program that compares two strings
and decides which among them is greater or whether
they are equal.
written by    :Okello Job Opiyo
reg no        :p15/37353/2016
course        :csc 112
date written  :29/11/2015
date compiled :29/11/2015*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	char string1[200];//declaration of character arrays
	char string2[200];
	
	printf("please enter first string\n");//asks user to enter string
	gets(string1);
	
	printf("please enter a second string\n");
	gets(string2);
	
	if (strcmp(string1,string2)==0)//compares the two strings
	{
		printf("the two strings are equal!!\n");//prints the result of the comparisson
	}
	else if (strcmp(string1,string2)>0)
	{
		printf("%s is greater than %s\n",string1,string2);
	}
	else if (strcmp(string1,string2)<0)
	{
		printf("%s is greater than %s\n",string2,string1);
	}
}


