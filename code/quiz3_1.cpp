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
	cout << "����(" << radius << ")" << endl;
}

Circle::~Circle() {
	cout << "�Ҹ�(" << radius << ")" << endl;
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
	// ��ġ 1 (location 1)
	Circle mainDonut;
	// ��ġ 2 (location 2)
	Circle mainPizza(300);
	// ��ġ 3 (location 3)
}

/*
 * ��� (result) / ���� (2)
����(200)
����(300)
����(200)
����(400)
����(500)
�Ҹ�(500)
�Ҹ�(400)
����(300)
�Ҹ�(300)
�Ҹ�(200)
�Ҹ�(300)
�Ҹ�(200)
 */
