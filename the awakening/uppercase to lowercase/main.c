/*this is a program that asks a user to enter a line 
of text then prints it out in both uppercase and lowercase.
written by   :Okello Job Opiyo
reg no       :p15/37353/2016
course       :csc 112
date written :28/11/2015
date compiled:28/11/2015*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main()
{
    char s[100];//declaration of string variable as a char array

    printf("please enter a line of text\n");//asks user to enter a line of text
    gets(s);//acquires the line of text from user

    int i;

    for(i=0;s[i]!='\0';i++)
    {
        s[i]=toupper(s[i]);//converts each character of the string to uppercase
    }
    
     printf("Text converted to uppercase");
     puts(s);

    for(i=0;s[i]!='\0';i++)
    {
        s[i]=tolower(s[i]);//converts each character of the string to lowercase
        
   }
     printf("Text converted to lowercase %s\n",s);

    
}

