/*this is a program that combines a sun function
 and a result funtion which is then printedon the
  screen.
  written and compiled by okello job opiyo.
  reg no.p15/37353/2016.
  date: 4/11/2015*/

#include <stdio.h>
#include <stdlib.h>

int sum(int a,int b,int c);//funtion prototype
int ans(int result);//function prototype

void main()//declares main function
{
	int a,b,c,result,answer;
	printf("enter three numbers\n");
	scanf("%d%d%d",&a,&b,&c);
	
	result=sum(a,b,c);
	answer=ans(result);//second function obtains value from here
		
}

int sum (int a,int b,int c)//declares first function
{
	return a+b+c;
}

		
int ans(result)//declares second function
{
	printf("the sum of the numbers is %d\n",result);
}



/* in second function we use void main(result) because the function
does not do anything but instead acquires value to print from the 
function of the results in the main funtion. if the function was 
carrying out any operation then we would have used int (....) or
 name of function (..name of the function..).*/
