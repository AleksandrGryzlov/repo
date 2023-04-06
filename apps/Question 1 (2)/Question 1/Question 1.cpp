//Aleksandr Gryzlov
//03/09/2022
//Question 1

#include <iostream>
#include <cmath>
using namespace std;

class Root
{
private:
	//attributes
	double Xcoordinates, Ycoordinates, Radius, Angle;

public:
	//construct
	Root(double x, double y) {
		Xcoordinates = x;
		Ycoordinates = y;
		FindRoot(Xcoordinates, Ycoordinates);
		FindTan(Xcoordinates, Ycoordinates);
	}

	void FindRoot(double x, double y) {
		Radius = sqrt(x*x + y*y);
	}

	void FindTan(double x, double y) {
		Angle = atan(y / x);
	}

	//methods
	double getX() {
		return Xcoordinates;
	}
	double getY() {
		return Ycoordinates;
	}
	double getRoot() {
		return Radius;
	}
	double getAngle() {
		return Angle;
	}
};

int main()
{
	double xIn, yIn;
	cout << "Etner x coordinate: ";
	cin >> xIn;
	cout << "Enter y coordinate: ";
	cin >> yIn;
	Root Class(xIn, yIn);
	cout << "Radius: " << Class.getRoot() << " in coordinate x: " << Class.getX() << " in coordinate y: " << Class.getY() << endl;
	cout << "Angle: " << Class.getAngle() << " in coordinate x: " << Class.getX() << " in coordinate y: " << Class.getY() << endl;
	return 0;
}