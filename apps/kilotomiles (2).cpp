#include <iostream>
using namespace std;
int main()
{
	float kilometers, miles, multi;

	cout << "Please enter number of kilometers" << endl;
	cin >> kilometers;
	multi = 0.621;
	miles = kilometers * multi;
	cout << "The amount of " << kilometers << " kilometers equals " << miles << " miles" << endl;
	return 0;
}

