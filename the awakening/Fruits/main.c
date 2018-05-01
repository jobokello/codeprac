/*This is a program that asks a user to select which 
fruit they like.
written by Okello Job Opiyo
reg no: p15/37353/2016
date: 21/10/2015*/
#include <stdio.h>
#include <stdlib.h>

void main()
{
	char fruit;
	printf("which fruit do you like?\na)apple\nb)banana\nc)cherries\nd)guavas\ne)avocados\n");
	scanf("%c",&fruit);
	switch(fruit)
	{
		case 'a':
		 printf("you like apples\n");
		 break;
		case 'b':
		 printf("you like bananas\n");
		 break;
		case 'c':
		 printf("you like cherries\n");
		 break;
		case 'd':
		 printf("you like guavas\n");
		 break;
		case 'e':
		 printf("you like avocados\n");
		 break;
		default:
		 printf("you entered an invalid choice!!!\n");
	}
}
