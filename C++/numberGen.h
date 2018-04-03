#include <iostream>

using namespace std;
class NumberGen
{
public:
	int num1;
	int num2;

	int questNum()
	{
		num1 = 1 + rand() % 9;
		num2 = 1 + rand() % 9;
	}
	
};