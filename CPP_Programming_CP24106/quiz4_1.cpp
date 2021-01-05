#include <iostream>
using namespace std;

class Point2D {
	int x, y;
public:
	Point2D() : x(0), y(0) {}
	Point2D(int x, int y = 0) : x(x), y(y) {}

	Point2D& operator+=(Point2D& point) {
		x += point.x;
		y += point.y;
		return *this;
	}
	/*
	friend Point2D& operator+=(Point2D& p1, Point2D& p2) {
		p1.x += p2.x;
		p1.y += p2.y;
		return p1;
	}
	*/
	Point2D operator+(Point2D& p1) const {
		return Point2D(p1.x + x, p1.y + y);
	}

	friend ostream& operator<<(ostream& os, const Point2D& point);

};

ostream& operator<<(ostream& os, const Point2D& point) {
	os << "(" << point.x << ", " << point.y << ")";
	return os;
}

int main() {
	Point2D p1;							// 1
	Point2D p2(5);						// 2
	Point2D p3(3, -2);			    // 3
	//cout << p1 += p3 << endl;		    // 4
	cout << p2 + p3 << endl;		    // 5
	return 0;
}
