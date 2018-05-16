/*This is a program of three who participate in a game of rolling dice.
written by      :Okello Job Opiyo
reg no          :p15/37353/2016
date written    :2/12/2015
date compiled   :2/12/2015*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status{CONTINUE,WON,LOST};//enumerated constants represent game status

int rollDice(void);//function prototype


int main()
{
    char p1[50],p2[50],p3[50];//character array declaration to hold names of players
    char *pId[3]={"GOC_001","GOC_002","GOC_003"};//character array declaration and initialization to hold player IDs
    int roller1=1,i,Win[3],j;//integer declaration
    int roller2=1,roller3=1,sum[6],No_of_Rolls[3]={'\0'};
    Win[0]=0;Win[1]=0;Win[2]=0;//initialization
    enum Status gameStatus;//declaring variable gameStatus as our enumerated data-type-Status

    srand(time(NULL));//passing value of time to function srand so as to generate random values


    printf("\nGAME OF CHANCE - CRAPS\n");//prints on screen
    printf("----------------------\n\n");

    printf("Enter name of Player 1: ");
    gets(p1);
    printf("Enter name of Player 2: ");
    gets(p2);
    printf("Enter name of Player 3: ");
    gets(p3);

    printf("\nPlayer Details:\n\nPlayer ID    Name\n");
    printf("%s      %s\n",pId[0],p1);//prints player ID and Name on Screen
    printf("%s      %s\n",pId[1],p2);
    printf("%s      %s\n",pId[2],p3);
    printf("\n");

    for(j=0;j>-1;j++){//infinite loop to enable the game to run to its completion (end-point unknown)

    printf("%s, it's your turn, press '0' and then hit Enter to roll dice. ", p1);//player 1's turn
    scanf("%d",&roller1);


    for(i=0;i>-1;i++){//player 1's loop. rolls dice and determines whether lost or won round
    if(roller1==0){

       sum[0]=rollDice();//first roll of the dice
       No_of_Rolls[0]++;//counts number of rolls

    //determine game status based on sum of dice
    switch(sum[0]){

        //win on first roll
    case 7:
    case 11:
        gameStatus=WON;
        Win[0]++;//counts number of wins
        break;

        //lose on first roll
    case 2:
    case 3:
    case 12:
        gameStatus=LOST;
        break;

        //remember point
    default:
        gameStatus=CONTINUE;
        printf("Point is %d\n", sum[0]);
        break;//optional
    }
        //while game not complete
    while(gameStatus==CONTINUE){
        sum[1]=rollDice();//roll dice again
        No_of_Rolls[0]++;//counts number of rolls

        //determine game status
        if(sum[1]==sum[0]){//win by making point
            gameStatus=WON;//game over, player won
            Win[0]++;//counts number of wins
        }else{
            if(sum[1]==7){//lose by rolling 7
                gameStatus=LOST;
            }
        }
    }

    //Display won/lost message
    if(gameStatus==WON){//did player win?
        printf("%s, you win.\n\n",p1);
    }else{//player lost
        printf("%s, you lose.\n\n",p1);
    }
    }else{
        printf("\nApplication Error! System is terminating...\n");
        //exits program
    }
    if(gameStatus==WON||gameStatus==LOST){//checks whether gameStatus is won or lost and exits player 1's infinite loop accordingly
        break;
    }
    }

    printf("%s, it's your turn, press '0' and then hit Enter to roll dice. ", p2);//player 2's turn
    scanf("%d",&roller2);

    for(i=0;i>-1;i++){//infinite loop for player 2. Determines whether player 2 has won or lost
    if(roller1==0){

       sum[2]=rollDice();//first roll of the dice
       No_of_Rolls[1]++;//counts number of rolls

    //determine game status based on sum of dice
    switch(sum[2]){

        //win on first roll
    case 7:
    case 11:
        gameStatus=WON;
        Win[1]++;//counts number of wins
        break;

        //lose on first roll
    case 2:
    case 3:
    case 12:
        gameStatus=LOST;
        break;

        //remember point
    default:
        gameStatus=CONTINUE;
        printf("Point is %d\n", sum[2]);
        break;//optional
    }
        //while game not complete
    while(gameStatus==CONTINUE){
        sum[3]=rollDice();//roll dice again
        No_of_Rolls[1]++;//counts number of rolls

        //determine game status
        if(sum[3]==sum[2]){//win by making point
            gameStatus=WON;//game over, player won
            Win[1]++;//counts number of wins
        }else{
            if(sum[3]==7){//lose by rolling 7
                gameStatus=LOST;
            }
        }
    }

    //Display won/lost message
    if(gameStatus==WON){//did player win?
        printf("%s, you win.\n\n",p2);
    }else{//player lost
        printf("%s, you lose.\n\n",p2);
    }
    }else{
        printf("\nApplication Error! System is terminating...\n");
        //exits program
    }
    if(gameStatus==WON||gameStatus==LOST){//checks whether gameStatus is won or lost and exits player 2's infinite loop accordingly
        break;
    }
    }

    printf("%s, it's your turn, press '0' and then hit Enter to roll dice. ", p3);//player 3's turn
    scanf("%d",&roller3);

    for(i=0;i>-1;i++){//infinite loop for player 3. Determines whether player has won or lost
    if(roller1==0){

       sum[4]=rollDice();//first roll of the dice
       No_of_Rolls[2]++;//counts number of rolls

    //determine game status based on sum of dice
    switch(sum[4]){

        //win on first roll
    case 7:
    case 11:
        gameStatus=WON;
        Win[2]++;//counts number of wins
        break;

        //lose on first roll
    case 2:
    case 3:
    case 12:
        gameStatus=LOST;
        break;

        //remember point
    default:
        gameStatus=CONTINUE;
        printf("Point is %d\n", sum[4]);
        break;//optional
    }
        //while game not complete
    while(gameStatus==CONTINUE){
        sum[5]=rollDice();//roll dice again
        No_of_Rolls[2]++;//counts number of rolls

        //determine game status
        if(sum[5]==sum[4]){//win by making point
            gameStatus=WON;//game over, player won
            Win[2]++;
        }else{
            if(sum[5]==7){//lose by rolling 7
                gameStatus=LOST;
            }
        }
    }

    //Display won/lost message
    if(gameStatus==WON){//did player win?
        printf("%s, you win.\n\n",p3);
    }else{//player lost
        printf("%s, you lose.\n\n",p3);
    }
    }else{
        printf("\nApplication Error! System is terminating...\n");
        //exits program
    }
    if(gameStatus==WON||gameStatus==LOST){//checks whether gameStatus is won or lost and exits player 3's infinite loop accordingly
        break;
    }
    }

    if(Win[0]>=2&&Win[1]>=2&&Win[2]>=2){//checks to see whether each player has won at least twice, then exits the outer infinite loop accordingly
        break;
    }
    }

    //system("cls");

    printf("\nPlayer ID   No. of Rolls  No. of Wins\n");
    printf("%s          %d            %d\n",pId[0],No_of_Rolls[0],Win[0]);//prints results on screen(player ID, Number of rolls and Number of wins
    printf("%s          %d            %d\n",pId[1],No_of_Rolls[1],Win[1]);
    printf("%s          %d            %d\n",pId[2],No_of_Rolls[2],Win[2]);


    return 0;
}

int rollDice(void){
    int die1,die2;// 1st and 2nd dice respectively
    int workSum;//sum of dice

    die1= 1+(rand()%6);//pick random die 1 value
    die2= 1+(rand()%6);//pick random die 2 value
    workSum=die1+die2;//sum of die 1 and die 2

    //display results of this roll
    printf("Player rolled %d + %d = %d\n", die1, die2, workSum);
    return workSum;
}

