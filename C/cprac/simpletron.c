#include <stdio.h>
#include <stdlib.h>

/*Simpletron Machine Language(SML) implementation */

#define MEMSIZE 100 //declares the memory size of the simpletron

#define READ   10 //reads into a given memory location
#define WRITE  11 //writes fron a given memory location

#define LOAD  20 //loads from a given memory location into the accumulator
#define STORE 21 // stores from a given memory location into the accumulator

#define ADD      30 //adds a value from a given memory location to the value in the accumulator
#define SUBTRACT 31 //subtacts a value from a given memory location from the value in the accumulator
#define DIVIDE   32 //divides the value in the accumulator by the from a specific memory location
#define MULTIPLY 33 //multiplies the value in the accumulator by the value in the given memory location

#define BRANCH     40 //branches to specific memory location
#define BRANCHNEG  41 //branches to specific memory locatin if the value in the accumulator is negative
#define BRANCHZERO 42 //branches to a specific memory location if the value in the accumulator is zero
#define HALT       43 //ends the program after all the instructions have been entered

int checkword(int word, int size); //function prototype
void dump(int acc, int icounter, int mem[]); //function prototype

//main function of the program
int main(void)
{
   int memory[MEMSIZE] = { 0 }, i, err = 0;

   int operationCode = 0; //all registers initialised to zero
   int instructionRegister = 0; 
   int accumulator = 0; 
   int operand = 0;

   printf("*** Welcome to Simpletron! ***\n"
          "*** Please enter your program one instruction ***\n"
		  "*** (or data word) at a time. I will type the ***\n"
          "*** location number and a question mark (?).  ***\n"
          "*** You then type the word for that location. ***\n"
          "*** Type the sentinel -99999 to stop entering ***\n"
          "*** your program.*** \n");
	   
   for(i = 0; i < MEMSIZE; i++) //initiates loading instructions into the program
   {

        
    	while(1) // while the statement is true data is entered
    	{
        	printf("%.2d ?? ", i);
        	scanf("%d", &memory[i]);

	 		if(memory[i] == -99999) 
	 		{
	    		memory[i] = 0;
	    		i = MEMSIZE; 
	    		break;
	 		}

	 		if( checkword(memory[i], MEMSIZE) ) //calls the checkword function
	 		{
	    		printf("*** Invalid instruction: %d\n", memory[i]);
	    		printf("*** Please retype it or exit.\n");
	 		}

	 		else
	 		{
	 			break;
	 		}
		} 
	}	

   printf("*** Program loading completed ***\n"
	  	  "*** Program execution begins  ***\n\n");

   for(i = 0; i < MEMSIZE; i++) 
   {
	    instructionRegister = memory[i]; //instruction register will obtain its word from memory location memory[i] and will execute it.

	    operationCode = instructionRegister / 100;
	    operand = instructionRegister % 100;

	    if(operationCode >= BRANCH)
	    {
	    	--operand;
	    }
     
	    switch(operationCode) 
	    {
			case READ: 
				
				printf("Enter a Number: ");
		    	scanf("%d", &memory[operand]);
			break;//this will read a newv value into the memory location given by the operand number

			case WRITE:
				printf("\n==============================================================");
				printf("\nMEMORY LOCATION : %.2d\nRESULT          : %d\n\n", operand ,memory[operand]);
			break;// this will print a the value within the memory location bearing the operand number

			case LOAD:
				accumulator = memory[operand];
			break;//this will load the value in the first memory location into the memory location of the accumulator

			case STORE:
				memory[operand] = accumulator;
			break;//moves  the word in the accumulator into a new memory location

			case ADD:
				accumulator += memory[operand];
					if(accumulator > +9999 || accumulator <-9999)
					{
						err = 1;
					}
			break;//will add the second value into the value in the accumulator and leave the result in the accumulator 

			case SUBTRACT:
				accumulator -= memory[operand];
					if(accumulator > +9999 || accumulator <-9999)
					{
						err = 1;
					}
			break;// will subtract a the second value from the value in the accumulator and leave the result in the accumulator

			case DIVIDE:
				if(memory[operand] != 0)
				{
					accumulator /= memory[operand];	
				}
				else if( memory[operand] == 0 )
				{
					err = 2;
					accumulator = 0;
				}			       
			break;//will use the second value entered to divide the value in the accumulator

			case MULTIPLY:
				accumulator *= memory[operand];
					if(accumulator > +9999 || accumulator <-9999)
					{
						err = 1;
					}	
			break;// will multiply the value in the accumulator by the new value from memory operand

			case BRANCH:
				i = operand;
			break;//will move to another memory location

			case BRANCHNEG:
				if(accumulator < 0)
				{
					i = operand;
				}
			break;//will move to another memory location if the accumulator value is negative

			case BRANCHZERO:
				if(!accumulator)
				{
					i = operand;
				}
		    break;//will move to another memory location if the accumulator value is zero

			case HALT:
				printf("*** Simpletron execution terminated ***\n");
				dump(accumulator, i, memory);
				return 0;
			break;
			
			case 0:
			break;

			default:
				printf("*** unknown error: %d\n", instructionRegister);
				exit(-1);
			break;
		}
		
		if(err) 
	    {
			switch(err) 
			{
			case 1:
		    	printf("*** Out of the accumulator limit ***\n"); 
		    	accumulator = 0;
			break;

			case 2:
				printf("*** Attempt to divide by zero ***\n");
			break;
			}
		
		    printf("*** Simpletron execution abnormally terminated ***\n");
		    dump(accumulator, i, memory);
		    exit(-1);
	    }//check for errors in the instructions entered

	} 

	dump(accumulator, i, memory);

	return 0;
} 


int checkword(int word, int size) //checks the word entered to acquire instruction in memory location memory[i]
{
	if(word < 0 || word > 9999 || word % 100 >= size) 
	{
    	return 1;
    }

    switch(word / 100) //dividing by 100 will only give the operation code
    {
	    case READ:
	    case WRITE:
	    case LOAD:
	    case STORE:
	    case ADD:
	    case SUBTRACT:
	    case DIVIDE:
	    case MULTIPLY:
	    case BRANCH:
	    case BRANCHNEG:
	    case BRANCHZERO:
	    case HALT:
	    case 0:
	    break;
	    default:
	    return 1;
    } 

    return 0;
} 

/*dump file function to show memory locations*/
void dump(int acc, int icounter, int mem[])
{
    int i, j;

    printf("\nREGISTERS:\n");
    printf("accumulator\t\t%c%.4d\ninstructionCounter\t   %.2d\ninstructionRegister\t%c%.4d\noperationCode\t\t   %.2d\noperand\t\t\t   %.2d\n", acc < 0 ? '-' : '+', acc < 0 ? -acc : acc, icounter, mem[icounter] < 0 ? '-' : '+', mem[icounter] < 0 ? -mem[icounter] : mem[icounter], mem[icounter] / 100, mem[icounter] % 100);
      
    printf("\nMEMORY:\n");

    printf("%3c", ' ');

    for(i = 0; i < 10; i++)
    printf("%5d ", i);
    printf("\n");
    
    for(i = 0; i < MEMSIZE; i += 10) 
    {
	    printf("%.2d", i);
	    for(j = i; j < i+10; j++) 
	    {
		    printf(" %c%.4d", mem[j] < 0 ? '-' : '+', mem[j] < 0 ? -mem[j] : mem[j]);
	    }
	    printf("\n");
    }

} 
