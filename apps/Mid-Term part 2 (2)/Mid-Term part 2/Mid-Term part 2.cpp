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
	double Xcoordinates, Ycoordinates;

public:
	//construct
	Root(double x, double y) {
		Xcoordinates = x;
		Ycoordinates = y;
	}

	//methods
	void Print() {
		cout << "Coordinates x=" << Xcoordinates << " Coordinates y=" << Ycoordinates << endl;
	}

	double getX() {
		return Xcoordinates;
	}
	double getY() {
		return Ycoordinates;
	}
};

int main()
{
	double InX, InY;
	cin >> InX;
	cin >> InY;
	Root(InX, InY);
}