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
			throw("����");
		}
	}

	virtual void show() {
		cout << modelName << " : ���� ���� " << paper << "��";
	}
};

class InkJetPrinter : public BasePrinter {
	int ink;
public:
	InkJetPrinter(string modelName, int paper, int ink): BasePrinter(modelName, paper), ink(ink) {}

	void print(int pages) override {
		BasePrinter::print(pages);
		if (ink - pages < 0) {
			throw("��ũ");
		}
		paper -= pages;
		ink -= pages;
	}

	void show() override {
		BasePrinter::show();
		cout << ", ���� ��ũ " << ink;
	}
};

class LaserPrinter : public BasePrinter {
	int toner;
public:
	LaserPrinter(string modelName, int paper, int toner) : BasePrinter(modelName, paper), toner(toner) {}

	void print(int pages) override {
		BasePrinter::print(pages);
		if (toner - pages < 0) {
			throw("���");
		}
		paper -= pages;
		toner -= pages;
	}

	void show() override {
		BasePrinter::show();
		cout << ", ���� ��� " << toner;
	}
};

void output(BasePrinter* p) {
	p->show();
	cout << endl;
}

int main() {
	InkJetPrinter* ip = new InkJetPrinter("Officejet V40", 5, 2);
	LaserPrinter* lp = new LaserPrinter("SCX-6x45", 3, 20);
	std::cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
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
