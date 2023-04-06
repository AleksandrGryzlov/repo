#include <iostream>
using namespace std;
int main()
{
	float pi = 3.14159, Area, Radius, Diameter;
	int NumberSlices;
	cout << "Please enter the diameter of pizza: ";
	cin >> Diameter;
	Radius = Diameter / 2;
	Area = pi * Radius * Radius;
	NumberSlices = Area / 14.125;
	cout << "Your pizza can be cut into " << NumberSlices << " slices" << endl;
	return 0;
}

