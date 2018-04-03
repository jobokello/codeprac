#include <iostream>
#include <cstdlib>
#include "numberGen.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int answer = 0;
	int questionNumber = 1;
	int correctResponse;
	int wrongResponse;
	int correctAnswer = 0;
	int wrongAnswer = 0;
	int count = 0;

	NumberGen ng1;
	cout << "Welcome to your Maths Multipliction Practice\n============================================" << endl;

	ng1.questNum();

	while(count < 10)
	{
		cout << "Question " << questionNumber << endl;
		cout << "How much is " << ng1.num1 << " times " << ng1.num2 << "?\nAnswer: " << endl;
		cin >> answer;

		if(answer == (ng1.num1 * ng1.num2))
		{
			cout << "count = " << count << endl;
			correctResponse = 1 + rand() % 4;

			switch(correctResponse)
			{
				case 1:
					cout << "\n\nVery Good\n\n" << endl;
					break;
				case 2:
					cout << "\n\nExecellent\n\n" << endl;
					break;
				case 3:
					cout << "\n\nNice Work\n\n" << endl;
					break;
				case 4:
					cout << "\n\nKeep Up The Nice Work\n\n" << endl;
					break;
			}
			correctAnswer++;
		}
		else
		{
			while((answer != (ng1.num1 * ng1.num2)) && (count < 10))
			{
				wrongAnswer++;

				cout << "count = " << count << endl;
				wrongResponse = 1 + rand() % 4;

				switch(wrongResponse)
				{
					case 1:
						cout << "\n\nNo!!\nPlease try again.\nAnswer: \n\n" << endl;
						cin >> answer;
						break;
					case 2:
						cout << "\n\nWrong!!\nPlease once more.\nAnswer: \n\n" << endl;
						cin >> answer;
						break;
					case 3:
						cout << "\n\nWrong answer!!\nDon't Give Up.\nAnswer: \n\n" << endl;
						cin >> answer;
						break;
					case 4:
						cout << "\n\nNo!!\nKeep Trying.\nAnswer: \n\n" << endl;
						cin >> answer;
						break;
				}
				count++;
			}

			cout << "\n\nCorrect\n\n"	<< endl;
		}

		ng1.questNum();

		questionNumber++;
		count++;
	}

	cout << "correctAnswer = " << correctAnswer << endl;
	cout << "wrongAnswer = " << wrongAnswer << endl;

	if(((correctAnswer + wrongAnswer)/100) >= 0.75)
	{
		cout << "Congratulations, you are ready to go to the next level!" << endl;
	}
	else if(((correctAnswer + wrongAnswer)/100) < 0.75)
	{
		cout << "Please ask your teacher for more help" << endl;
	}

	cout << "Good Bye!" << endl;

	return 0;
}