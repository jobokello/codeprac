/*
Okello Job Opiyo
P15/37353/2016
CSC 411
RSA encryption
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int statPhi = 0;

int standardPhi(int phi)
{
	statPhi = phi;

	printf("standard Phi is: %d\n", statPhi);
}

//extended euclidian 
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
	row1Den = myE;
	row2Den = row1Start;

	printf("first phase\n%d\t%d\n%d\t%d\n",row1Num, row2Num, row1Den, row2Den);

	while(row1SubResult != 1)
	{
		//begin row 1 division
	
		if (row1Den == 0)
		{
			/* code */
			printf("row1Den = %d\n", row1Den);
		}
		row1DivResult = row1Num/row1Den;

		printf("the division\n%d / %d = %d\n", row1Num, row1Den, row1DivResult);

		//both rows multiplication
		row1MultResult = row1Den * row1DivResult;
		row2MultResult = row2Den * row1DivResult;

		printf("the multiplication\n%d * %d = %d\t%d * %d = %d\n",row1Den,row1DivResult,row1MultResult,row2Den,row1DivResult,row2MultResult);

		//both rows subtraction
		row1SubResult = row1Num - row1MultResult;
		row2SubResult = row2Num - row2MultResult;

		printf("the subtraction\n%d - %d = %d\t%d - %d = %d\n",row1Num,row1MultResult,row1SubResult,row2Num,row2MultResult,row2SubResult);

		if (row1SubResult != 1)
		{
			if(row2SubResult < 0)
			{
				newRow2Den = row2SubResult + statPhi;

				printf("less than 1 so addition with the %d\n%d + %d = %d\n", statPhi, row2Num, statPhi ,newRow2Den);
			}
			else
			{
				newRow2Den = row2SubResult;
			}

			printf("final row 2 denominator = %d\n", newRow2Den);

			//newRow1Num = row1Den;
			//newRow1Den = row1SubResult;

			row1Num = row1Den;
			row2Num = row2Den;
			row1Den = row1SubResult;
			row2Den = row2SubResult = newRow2Den; 

			//getD(newRow1Num,newRow1Den,newRow2Den);
		}
		else if(row1SubResult == 1) 
		{

			int finalD;

			if(row2SubResult < 0)
			{
				newRow2Den = row2Num + statPhi;
			}
			else
			{
				finalD = newRow2Den = row2SubResult;
			}

			//returns private key
			return finalD;
		}
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
	int diglet;
	char letter;
	int strlenghth;
	char plaintext[1024];
	int plaintextToNum[1024];
	int encryptednumbers[1024];
	int decryptednumbers[1024];
	int i,j,k,l;
	long long int mPowerD;

	p = 5;
	q = 11;
	e = 7;

	n = p * q;

	phi = (p-1)*(q-1);

	standardPhi(phi);


	printf("n is: %d\nphi is: %d\n", n, phi);


	//gets string to encrypt
	printf("enter a string to encrypt:\n");
	scanf("%s", plaintext);
	strlenghth = strlen(plaintext);
	printf("size of the string is %d\n", strlenghth);

	//convert string into number
	for(i=0; i < strlenghth; i++)
	{
		plaintextToNum[i] = c_to_n(plaintext[i]); 
	}

	printf("the numbers converted are: \n");

	for(i=0; i < strlenghth; i++)
	{
		printf(" %d", plaintextToNum[i]); 
	}
	printf("\n");

	//encryptiption of the string
	for(i=0; i < strlenghth; i++)
	{
		int mPowerE = (pow(plaintextToNum[i],e));
		encryptednumbers[i] = mPowerE % n; 
	}

	printf("the encryption is: ");

	for(i=0; i < strlenghth; i++)
	{
		printf(" %d", encryptednumbers[i]); 
	}
	printf("\n");

	//decryptiption

	//calls function for decryption
	printf("phi is %d\ne is %d\nrow1start is %d\n", phi,e,row1Start);

	d = getD(phi,e,row1Start);
	printf("d is %d\n", d);
	printf("n is %d\n", n);


	//prints out the decryption
	printf("number before decryption is: ");

	for(i=0; i < strlenghth; i++)
	{
		printf(" %d", encryptednumbers[i]); 
	}
	printf("\n");

	

	printf("initial mPowerD is %lld\n", mPowerD);
	
	for(i=0; i < strlenghth; i++)
	{
		mPowerD = (pow(encryptednumbers[i],d));
		printf("mPowerD = m is %d power %d = %lld\n", encryptednumbers[i],d,mPowerD);
		decryptednumbers[i] = mPowerD % n;
		printf("%d\n", decryptednumbers[i]);  
	}

	//prints out decryption in number form
	printf("the decryption in number form is: ");

	for(i=0; i < strlenghth; i++)
	{
		printf(" %d", decryptednumbers[i]); 
	}
	printf("\n");

	//prints out decryption in character form
	printf("the decryption in character form is: ");

	for(i=0; i < strlenghth; i++)
	{
		printf("%c", decryptednumbers[i]); 
	}
	printf("\n");


	
}