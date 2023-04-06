// This program uses a switch-case statement to assign a
// letter grade (A, B, C, D, or F) to a numeric test score.
#include <iostream>
using namespace std;
int main()
{
	int testScore;
	cout << "Enter your test score and I will tell you\n";
	cout << "the letter grade you earned: ";
	cin >> testScore;
	testScore = testScore / 10;
	switch (testScore)
	{
		case 0:  case 1: case 2: case 3: case 4: case 5:
			cout << "Your grade is F.\n";
			break;
		case 6:
			cout << "Your grade is D.\n";
			break;
		case 7:
			cout << "Your grade is C.\n";
			break;
		case 8:
			cout << "Your grade is B.\n";
			break;
		case 9:  case 10:
			cout << "Your grade is A.\n";
			break;
		default:
			cout << "That score isn't valid\n";
	}
	return 0;
}