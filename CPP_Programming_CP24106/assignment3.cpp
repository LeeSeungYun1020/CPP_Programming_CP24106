#include <iostream>
using namespace std;

class BasePrinter {
	string modelName;
protected:
	int paper;
public:
	BasePrinter(string modelName, int paper = 0): modelName(modelName), paper(paper) {}

	virtual void print(int pages) {
		if (paper - pages < 0) {
			throw("용지");
		}
	}

	virtual void show() {
		cout << modelName << " : 남은 종이 " << paper << "장";
	}
};

class InkJetPrinter : public BasePrinter {
	int ink;
public:
	InkJetPrinter(string modelName, int paper, int ink): BasePrinter(modelName, paper), ink(ink) {}

	void print(int pages) override {
		BasePrinter::print(pages);
		if (ink - pages < 0) {
			throw("잉크");
		}
		paper -= pages;
		ink -= pages;
	}

	void show() override {
		BasePrinter::show();
		cout << ", 남은 잉크 " << ink;
	}
};

class LaserPrinter : public BasePrinter {
	int toner;
public:
	LaserPrinter(string modelName, int paper, int toner) : BasePrinter(modelName, paper), toner(toner) {}

	void print(int pages) override {
		BasePrinter::print(pages);
		if (toner - pages < 0) {
			throw("토너");
		}
		paper -= pages;
		toner -= pages;
	}

	void show() override {
		BasePrinter::show();
		cout << ", 남은 토너 " << toner;
	}
};

void output(BasePrinter* p) {
	p->show();
	cout << endl;
}

int main() {
	InkJetPrinter* ip = new InkJetPrinter("Officejet V40", 5, 2);
	LaserPrinter* lp = new LaserPrinter("SCX-6x45", 3, 20);
	std::cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
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
