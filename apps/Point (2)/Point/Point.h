class Point {
private:
	double x;
	double y;
	double z;
public:
	Point() {
		x = 0.0, y = 0.0, z = 0.0; 
	}
	Point(double newX, double newY, double newZ) {
		x = newX, y = newY, z = newZ;
	}
	void setCoordinates(double x, double y, double z);
	void move(double offsetX, double offsetY, double offsetZ);
	void move(Point& offset);
	double getX() const;
	double getY() const;
	double getZ() const;
};