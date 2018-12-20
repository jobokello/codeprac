#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int getD(int myPhi,int myE,int row1Start)
{
	int row1Num,row1Den;
	int row2Num,row2Den;
	int newRow1Num,newRow1Den;
	int newRow2Den;
	int row1DivResult;
	int row1MultResult;
	int row2MultResult;
	int row1SubResult;
	int row2SubResult;

	row2Num = row1Num = myPhi;
	row2Den = myE;
	row2Den = row1Start;

	//begin row 1 division
	row1DivResult = row1Num/row1Den;

	//both rows multiplication
	row1MultResult = row1Den * row1DivResult;
	row2MultResult = row2Den * row1DivResult;

	//both rows subtraction
	row1SubResult = row1Num - row1MultResult;
	row2SubResult = row2Num - row2MultResult;

	if (row1SubResult != 1)
	{
		if(row2SubResult < 0)
		{
			newRow2Den = row2Num + row2SubResult;
		}
		else
		{
			newRow2Den = row2SubResult;
		}

		newRow1Num = row1Den;
		newRow1Den = row1SubResult;

		getD(newRow1Num,newRow1Den,newRow2Den);
	}
	else
	{
		return row1SubResult;
	}
}

int c_to_n(char c)
{
    int n = -1;
    static const char * const alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *p = strchr(alphabet, toupper((unsigned char)c));

    if (p)
    {
        n = p - alphabet;
    }

    return n;
}

int main(void)
{
	int p;
	int q;
	int n;
	int e;
	int d;
	int phi;
	int x;
	int det;
	int row1Start = 1;

	char letter;
	printf("enter a letter:\n");
	scanf("%c", &letter);
	printf("the letter numebr equivalent is %c \n", c_to_n(letter));

	p = 5;
	q = 11;
	e = 7;

	n = p * q;
	phi = (p-1)*(q-1);

	printf("n is: %d\nphi is: %d\n", n, phi);

	d = getD(phi,e,row1Start);

	printf("enter a letter:\n");
	scanf("%c", &letter);
	printf("the letter numebr equivalent is %d \n", c_to_n(letter));

	printf("d is %d\n", d);
}