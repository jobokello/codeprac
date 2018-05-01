#include<stdio.h>
#include<stdlib.h>

void main()
{
    int a,b,c,sum,product;
    printf("enter a three numbers a,b,c\n");
    scanf("%d%d%d", &a, &b, &c);

    sum = a + b + c;
    product=a*b*c;

    printf("the sum of the numbers is %d and the product is %d", sum, product);
}

