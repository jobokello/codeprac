#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int seats[10] = {0};
	int fclass = 0;
	int sclass = 5;
	int choice;
	int choice2;
	int booked = 0;
	int i;

	while(booked<10)
	{
	printf("which class will you fly?\n1.first class\n2.second\n");
	scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				if(fclass<5)
				{
					seats[booked]=1;
					booked++;
					fclass++;
				}
				else
				{
					printf("first class full\n1.try second class\n2.leave\n");
					scanf("%d",&choice2);

					switch(choice2)
					{
						case 1:
							seats[booked]=2;
							sclass++;
							booked++;
							break;

						case 2:
							break;
					}
				}

				break;
			case 2:
				seats[booked]=2;
				sclass++;
				booked++;
				break;
			default:
				break;
		}
	}

	for (i=0;i<10;i++)
	{
		printf("%d ",seats[i]);
	}

	return 0;
}
