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
			throw("����");
		}
		cout << "����Ʈ�Ͽ����ϴ�." << endl;
		availableCount -= pages;
		printedCount += pages;
	}

	virtual void show() {
		cout << model << " : ���� ���� " << availableCount << "��";
	}
};

class InkJetPrinter : public BasePrinter {
	int availableInk;
public:
	InkJetPrinter(string model, int paper, int ink) : BasePrinter(model, paper), availableInk(ink) {}

	void print(int pages) override {
		if (availableInk - pages < 0) {
			throw("��ũ");
		}
		BasePrinter::print(pages);
		availableInk -= pages;
	}

	void show() override {
		BasePrinter::show();
		cout << ", ���� ��ũ " << availableInk;
	}
};

class LaserPrinter : public BasePrinter {
	int availableToner;
public:
	LaserPrinter(string model, int paper, int toner) : BasePrinter(model, paper), availableToner(toner) {}

	void print(int pages) override {
		if (availableToner - pages < 0) {
			throw("���");
		}
		BasePrinter::print(pages);
		availableToner -= pages;
	}

	void show() override {
		BasePrinter::show();
		cout << ", ���� ��� " << availableToner;
	}
};

void output(BasePrinter* p) {
	p->show();
	cout << endl;
}

int main() {
	InkJetPrinter* ip = new InkJetPrinter("Officejet V40", 5, 2);
	LaserPrinter* lp = new LaserPrinter("SCX-6x45", 3, 20);
	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
	cout << "��ũ�� : ";
	ip->show();
	cout << endl;
	cout << "������ : ";
	lp->show();
	cout << endl;
	int printer, pages;
	char conti;
	BasePrinter* bp = nullptr;
	while (true) {
		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> printer >> pages;
		switch (printer) {
			case 1: // ��ũ��
				bp = ip;
				break;
			case 2: // ������
				bp = lp;
				break;
		}
		try {
			bp->print(pages);
		} catch (const char* s) {
			cout << s << "�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		}
		output(ip); //ip->show();
		output(lp); //lp->show();
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		cin >> conti;
		if (conti == 'y')
			continue;
		break;
	}
}