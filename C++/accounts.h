//header file for the new collaborator
//thank i now have access
//how do you find the file
//make some more
#include <iostream>

using namespace std;

class Accounts
{
	private:
		int accBal;

	public:
		Accounts(int initBal)
		{
			if ((accBal<0)||(accBal>0))
			{
				accBal = initBal;

				cout << "initial set to ksh. "<<initBal<<endl;
			}
			else
			{
				cout <<"the initial balance is correct."<<endl;
			}
		}

		void credit(int deposit)
		{
		 	accBal = accBal + deposit;
		}

		void debit(int withdraw)
		{
		 	if(withdraw > accBal)
		 	{
		 		cout<<"you cannot withdraw due to low balance"<<endl;
		 	}
		 	else
		 	{
		 		accBal = accBal - withdraw;
		 	}
		}

		 int getBalance()
		{
		 	return accBal;
		}
};
