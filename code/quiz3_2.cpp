#include <iostream>
using namespace std;
class Pizza {
public:
	int size;
	Pizza(int s) : size(s) {}
};

void f1(Pizza* p) {
	p->size *= 2;
}

void f2(Pizza& p) {
	p.size *= 2;
}

void f3(int& p) {
	p *= 2;
}

void f4(int* p) {
	*p *= 2;
}

int main() {
	Pizza pizza(10);
	cout << pizza.size << "인치 피자" << endl;
	f1(&pizza);
	cout << pizza.size << "인치 피자" << endl;
	f2(pizza);
	cout << pizza.size << "인치 피자" << endl;
	f3(pizza.size);
	cout << pizza.size << "인치 피자" << endl;
	f4(&pizza.size);
	cout << pizza.size << "인치 피자" << endl;
	return 0;
}

/*
 * 결과
 * 10인치 피자
 * 20인치 피자
 * 40인치 피자
 * 80인치 피자
 * 160인치 피자
 */