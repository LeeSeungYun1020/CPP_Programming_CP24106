#include <iostream>

using namespace std;

void swap(int& x, int& y) {
	int tem = x;
	x = y;
	y = tem;
}

void modify(int& x, int& y) {
	x *= 2;
	y += 8;
}

int main() {
	int a = 4, b = 8;
	swap(a, b);
	modify(a, b);
	modify(a, b);
	cout << a << endl;
	cout << b << endl;
}