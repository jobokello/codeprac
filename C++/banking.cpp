//backing practice simulates m-shwari and mpesa systems used in phones
#include <iostream>
#include <stdlib.h>
#include "accounts.h"

using namespace std;

int main(void)
{
	int choice;
	int accChoice;
	int withdraw;
	int deposit;
	int newBalance;
	Accounts ac1(0);
	Accounts ac2(0);
	cout<<"new balance for customer 1 is ksh."<<ac1.getBalance()<<endl;
	cout<<"new balance for customer 2 is ksh."<<ac2.getBalance()<<endl;

	accountSelect:cout<<"Which accounts would you like to view?\n1. accounts for customer 1\n2. accounts for customer 2\n3. exit"<<endl;
	cin>>choice;

	switch(choice)
	{
		case 1:
			accountOptions1:cout<<"Customer 1\nbanking options\n1. get account balance\n2. withdraw\n3. deposit\n4. back"<<endl;
			cin>>accChoice;
			switch(accChoice)
			{
				case 1:
					cout<<"Current balance is ksh."<<ac1.getBalance()<<endl;
					goto accountOptions1;
					break;
				case 2:
					cout<<"enter amount to withdraw"<<endl;
					cin>>withdraw;
					ac1.debit(withdraw);
					cout<<"new balance is ksh."<<ac1.getBalance()<<endl;
					goto accountOptions1;
					break;
				case 3:
					cout<<"enter amount to deposit"<<endl;
					cin>>deposit;
					ac1.credit(deposit);
					cout<<"new balance is ksh."<<ac1.getBalance()<<endl;
					goto accountOptions1;
					break;
				case 4:
					goto accountSelect;
					break;	
				default:
					cout<<"invalid choice.\ntry again\n\n"<<endl;
					goto accountOptions1;
					break;
			}
			break;
		case 2:
			accountOptions2:cout<<"Customer 2\nbanking options\n1. get account balance\n2. withdraw\n3. deposit\n4. back"<<endl;
			cin>>accChoice;
			switch(accChoice)
			{
				case 1:
					cout<<"Current balance is ksh."<<ac2.getBalance()<<endl;
					goto accountOptions2;
					break;
				case 2:
					cout<<"enter amount to withdraw"<<endl;
					cin>>withdraw;
					ac2.debit(withdraw);
					cout<<"new balance is ksh."<<ac2.getBalance()<<endl;
					goto accountOptions2;
					break;
				case 3:
					cout<<"enter amount to deposit"<<endl;
					cin>>deposit;
					ac2.credit(deposit);
					cout<<"new balance is ksh."<<ac2.getBalance()<<endl;
					goto accountOptions2;
					break;
				case 4:
					goto accountSelect;
					break;	
				default:
					cout<<"invalid choice.\ntry again\n\n"<<endl;
					goto accountOptions2;
					break;
			}
			break;
		case 3:
			exit(0);
			break;
		default:
			cout<<"wrong account please try again."<<endl;
			goto accountSelect;
			break;	
	}


	return 0;
}
