/*this is a program that asks a user to enter a number then it obtains the cube and square of the number.
written by Okello Job Opiyo reg no.p15/37353/2016*/
#include <stdio.h>
#include <stdlib.h>

int square(int num);//function prototype
int cube(int num);//funtion prototype
 void main()//declares main function
 {
 	int a,num_squared,num_cubed;//gives variables of the main function
 	
 	printf("enter a number a\n");//asks user to enter a number "a"
 	scanf("%d",&a);//obtains the number from the keyboard
 	
 	num_squared=square(a);//assigns the number
 	num_cubed=cube(a);//asigns the number
 	
 	printf("the square of %d is %d\n",a,num_squared);//prints the result on the screen
 	printf("the cube of %d is %d\n",a,num_cubed);
 }
 
 int square(int num)//declares first funtion
{
	return num*num;//defines the function
}

int cube(int num)//declares second function
{
	return num*num*num;//defines second function
}

 
 
 
 
 
 