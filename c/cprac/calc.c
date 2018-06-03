#include <stdio.h>
#include <stdlib.h>


void add(int a, int b)
{
	int ans = a + b;
	printf("the sum of %d and %d is %d\n",a, b, ans);
}

void subtract(int a, int b)
{
	if(a>b)
	{
		int ans = a - b;
		printf("the difference of %d and %d is %d\n",a, b, ans);
	}
	else
	{
		int ans = b - a;
		printf("the product of %d and %d is %d\n",a, b, ans);
	} 
}

void multiply(int a, int b)
{
	int ans = a * b;
	printf("the product of %d and %d is %d\n", a, b, ans);
}

void none()
{
	printf("you chose nothing\n");
}

int main(int argc, char const *argv[])
{
	int a, b, choice;
	void(*f[4])(int ,int) = {none, add, subtract, multiply};

	printf("enter two numbers:\n");
	scanf("%d%d",&a,&b);

	printf("what would you like to do with the numbers?\n1.add\n2.subtract\n3.multiply\n");
	scanf("%d", &choice);

	(*f[choice])(a, b);

	return 0;
}