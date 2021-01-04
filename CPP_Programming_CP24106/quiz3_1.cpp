#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	Circle(int radius);
	~Circle();
	double getArea() const;
};

Circle::Circle() : Circle(200) {}

Circle::Circle(const int radius) : radius(radius) {
	cout << "积己(" << radius << ")" << endl;
}

Circle::~Circle() {
	cout << "家戈(" << radius << ")" << endl;
}

double Circle::getArea() const {
	return 3.14 * radius * radius;
}

Circle globalPizza(200);
Circle globalDonut(300);

void f() {
	Circle fDonut(400);
	Circle fPizza(500);
}

int main() {
	// 困摹 1 (location 1)
	Circle mainDonut;
	// 困摹 2 (location 2)
	Circle mainPizza(300);
	// 困摹 3 (location 3)
}

/*
 * 搬苞 (result) / 沥翠 (2)
积己(200)
积己(300)
积己(200)
积己(400)
积己(500)
家戈(500)
家戈(400)
积己(300)
家戈(300)
家戈(200)
家戈(300)
家戈(200)
 */
