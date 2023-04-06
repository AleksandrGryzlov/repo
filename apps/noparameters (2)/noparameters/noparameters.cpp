#include <iostream>
#include <iomanip>
using namespace std;

//Aleksandr Gryzlov

float converter(float&);
int input;

int main()
{
	float num, numShow;
	cout << "Options:\n1.Miles to Kilometers\n2.Kilometers to Miles\n3.Quit" << endl;
	cin >> input;
	while (input < 1 || input >3)
	{
		cout << "Wrong option, Please try again" << endl;
		cin >> input;
	}
	while (input != 3)
	{
		cout << "\nPlease enter number you want to conver: ";
		cin >> num;
		numShow = num;
		cout << endl;
		if (input == 1)
			cout << numShow << " miles = " << converter(num) << " kilometers" << endl << endl;
		else cout << numShow << " kilometers = " << converter(num) << " miles" << endl << endl;

		cout << "Options:\n1.Miles to Kilometers\n2.Kilometers to Miles\n3.Quit" << endl;
		cin >> input;
		while (input < 1 || input >3)
		{
			cout << "Wrong option, Please try again" << endl;
			cin >> input;
		}
	}
	return 0;
}

float converter(float& number)
{
	if (input == 1)
		number = number * 1.61;
	else number = number * 0.621;
	return number;
}