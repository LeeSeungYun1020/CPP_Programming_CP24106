#include <iostream>

using namespace std;

class Circle {
	int radius;
	int x, y;
public:
	Circle(int radius, int x = 0, int y = 0): radius(radius), x(x), y(y) {}
	double getArea() const {
		return radius * 3.14 * 3.14;
	}
	
	int getRadius() const {
		return radius;
	}

	void setRadius(int radius) {
		this->radius = radius;
	}
};

template <class T>
void print(T* array, int n) {
	for (int i = 0; i < n; i++)
		cout << array[i] << '\t';
	cout << endl;
}

void print(char* array, int n) {
	for (int i = 0; i < n; i++)
		cout << (int)array[i] << '\t';
	cout << endl;
}

int main() {
	char c[5] = { 1, 2, 3, 4, 5 };
	double d[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	Circle circle[3] = {
		Circle(3),
		Circle(2, 3),
		Circle(3, 1, 4)
	};
	print(c, 4);
	//print(circle, 3);
	print(d, 5);
}