#include "Point.h"

void Point::setCoordinates(double x, double y, double z)
{
	x = 2.5;
	y = 0;
	z = 2.0;
}

void Point::move(double offsetX, double offsetY, double offsetZ)
{
	offsetX = 0.1;
	offsetY = -0.1;
	offsetZ = 0.0;
}

void Point::move(Point& offset)
{
	// TODO: Get the offsets for each coordinate from the point
	// and then adjust coordinate values
	
}

double getX()
{
	// TODO: Well, get the value
}

double getY()
{
	// TODO: Well, get the value
}

double getZ()
{
	// TODO: Well, get the value
}
