// Aleksandr Gryzlov

#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
	float q1, q2, q3, q4, average;
	cout << setprecision(2) << fixed << showpoint;
	cout << "Please enter your water bill for quater 1: ";
	cin >> q1;
	cout << "Please enter your water bill for quater 2: ";
	cin >> q2;
	cout << "Please enter your water bill for quater 3: ";
	cin >> q3;
	cout << "Please enter your water bill for quater 4: ";
	cin >> q4;
	average = (q1 + q2 + q3 + q4) / 14;
	if (average >= 25)
	{
		if (average > 75)
			cout << "Your average monthly bill is " << average << "$ " << "You are using too much water!!!" << endl;
		else
			cout << "Your average monthly bill is " << average << "$ " << "You are using typical amount of water." << endl;
	}
	else
		cout << "Your average monthly bill is " << average << "$ " << "WOW! You are good at saving water!!!" << endl;
	return 0;
}