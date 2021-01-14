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
	cout << pizza.size << "��ġ ����" << endl;
	f1(&pizza);
	cout << pizza.size << "��ġ ����" << endl;
	f2(pizza);
	cout << pizza.size << "��ġ ����" << endl;
	f3(pizza.size);
	cout << pizza.size << "��ġ ����" << endl;
	f4(&pizza.size);
	cout << pizza.size << "��ġ ����" << endl;
	return 0;
}

/*
 * ���
 * 10��ġ ����
 * 20��ġ ����
 * 40��ġ ����
 * 80��ġ ����
 * 160��ġ ����
 */