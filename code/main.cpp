#include <iostream>
using namespace std;

class BasePrinter {
	string model;
	int availableCount;
	int printedCount;
public:
	BasePrinter(string model, int paper = 0) : model(model), availableCount(paper), printedCount(0) {}

	virtual void print(int pages) {
		if (availableCount - pages < 0) {
			throw("용지");
		}
		cout << "프린트하였습니다." << endl;
		availableCount -= pages;
		printedCount += pages;
	}

	virtual void show() {
		cout << model << " : 남은 종이 " << availableCount << "장";
	}
};

class InkJetPrinter : public BasePrinter {
	int availableInk;
public:
	InkJetPrinter(string model, int paper, int ink) : BasePrinter(model, paper), availableInk(ink) {}

	void print(int pages) override {
		if (availableInk - pages < 0) {
			throw("잉크");
		}
		BasePrinter::print(pages);
		availableInk -= pages;
	}

	void show() override {
		BasePrinter::show();
		cout << ", 남은 잉크 " << availableInk;
	}
};

class LaserPrinter : public BasePrinter {
	int availableToner;
public:
	LaserPrinter(string model, int paper, int toner) : BasePrinter(model, paper), availableToner(toner) {}

	void print(int pages) override {
		if (availableToner - pages < 0) {
			throw("토너");
		}
		BasePrinter::print(pages);
		availableToner -= pages;
	}

	void show() override {
		BasePrinter::show();
		cout << ", 남은 토너 " << availableToner;
	}
};

void output(BasePrinter* p) {
	p->show();
	cout << endl;
}

int main() {
	InkJetPrinter* ip = new InkJetPrinter("Officejet V40", 5, 2);
	LaserPrinter* lp = new LaserPrinter("SCX-6x45", 3, 20);
	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : ";
	ip->show();
	cout << endl;
	cout << "레이저 : ";
	lp->show();
	cout << endl;
	int printer, pages;
	char conti;
	BasePrinter* bp = nullptr;
	while (true) {
		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> printer >> pages;
		switch (printer) {
			case 1: // 잉크젯
				bp = ip;
				break;
			case 2: // 레이저
				bp = lp;
				break;
		}
		try {
			bp->print(pages);
		} catch (const char* s) {
			cout << s << "가 부족하여 프린트할 수 없습니다." << endl;
		}
		output(ip); //ip->show();
		output(lp); //lp->show();
		cout << "계속 프린트 하시겠습니까(y/n)>>";
		cin >> conti;
		if (conti == 'y')
			continue;
		break;
	}
}