#include<stdio.h>
#include<stdlib.h>
int main() {
	int num1, num2, num3, num4, num5,largest,smallest;
	printf("Enter five numbers...\n");
	scanf_s("%d%d%d%d%d",&num1,&num2,&num3,&num4,&num5);
	if(num1>num2){
		largest = num1;
		smallest = num2;
		if (largest < num3) {
			largest = num3;
		}
		if (largest < num4) {
			largest = num4;
		}
		if (largest < num5) {
			largest = num5;
		}
		if (smallest > num3) {
			smallest = num3;
		}
		if (smallest > num4) {
			smallest = num4;
		}
		if (smallest > num5) {
			smallest = num5;
		}
	}
	else {
		largest = num2;
		smallest = num1;
		if (largest < num3) {
			largest = num3;
		}
		if (largest < num4) {
			largest = num4;
		}
		if (largest < num5) {
			largest = num5;
		}
		if (smallest > num3) {
			smallest = num3;
		}
		if (smallest > num4) {
			smallest = num4;
		}
		if (smallest > num5) {
			smallest = num5;
		}
	}
	printf("You have entered : [ %d , %d , %d , %d , %d ]\n",num1,num2,num3,num4,num5);
	if (smallest == largest) {
		printf("All Numbers are equal\n");
	}
	else {
		printf("The largest is : %d and the smallest is : %d\n", largest, smallest);
	}
	return 0;
}