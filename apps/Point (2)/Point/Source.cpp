#include <iostream>
#include "Point.h"
using namespace std;
int main() {
	Point& point1 = new Point();
	Point& point2 = new Point(3.0, 3.0, 3.0);
	cout << point1.getX() << point1.getY() << point1.getZ() << endl;
	cout << point2.getX() << point2.getY() << point2.getZ() << endl;
	point1.setCoordinates(2.0, 1.0, 2.0);
	cout << point1.getX() << point1.getY() << point1.getZ() << endl;
	point1.move(point2);
	cout << point1.getX() << point1.getY() << point1.getZ() << endl;
	point2.move(3.0, 3.0, 3.0);
	return 0;
}