#include <iostream>

using namespace std;

/* 1 */
class Base {
	/* 2 */
	int a;
protected:
	Base() : a(1), b(1), c(1) {
		cout << b;
	}

	int b;

	void setA(int a) {
		this->a = a;
	}

	/* 3 */
	int getA() const {
		return a;
	}

public:
	int c;
};

/* 4 */
class Derived1 : virtual /* 5 */ public Base {
	int d;
protected:
	int e;
public:
	Derived1() : d{2}, e{1}, f{3} {
		cout << d;
	}

	int f;
};

/* 6 */
class Derived2 : virtual /* 7 */ protected Base {
	int g;
protected:
	int h;
public:
	Derived2() : g(3), h(2), i(1) {
		cout << g;
	}

	int i;
};


/* 8 */
class Derived3 : /* 9 */protected Derived1, /* 10 */public Derived2 {
	int j;
protected:
	int k;
public:
	int l;

	Derived3() : j(4), k(3), l(3) {
		cout << j;
	}

	void print() {

		cout << getA() << endl;

	}

};

int main() {
	Derived1 d1;
	Derived2* pd2 = new Derived2;
	Base* pb1 = static_cast<Base*>(new Derived2);
	Derived3 d3;
	Base* pb2 = static_cast<Base*>(&d3);
	// 문항 1 문장 삽입 위치
	cout << pb1->c << endl;
	return 0;
}
