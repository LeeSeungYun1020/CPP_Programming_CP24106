#include <iostream>

using namespace std;

class MyException {
	string message;
public:
	virtual ~MyException() = default;

	MyException(string message) {
		this->message = message;
	}

	/*virtual void print() const {
		cout << message << endl;
	}*/
	virtual void print() const = 0;

	string getMessage() const {
		return message;
	}

};

class MonthException : public MyException {
public:
	MonthException(string message): MyException(message) {}

	void print() const override {
		cout << "Month Exception: " << getMessage();
	}
};

class DayException : public MyException {
public:
	DayException(string message) : MyException(message) {}

	void print() const override {
		cout << "Day Exception: " << getMessage();
	}
};

class MyCalendar {
	int year, month, day;
public:
	MyCalendar(int year, int month = 1, int day = 1) {
		if (month > 12 || month < 1) {
			throw MonthException("�� �Է� ����");
		}
		if (day > 31 || day < 1) {
			throw DayException("�� �Է� ����");
		}
	}
};


int main() {
	int year, month, day;
	while (true) {
		try {
			cout << "��¥ �Է�(�� �� ��): ";
			cin >> year >> month >> day;
			MyCalendar c(year, month, day);
			break;
		} catch (MonthException e) {
			e.print();
		} catch (DayException e) {
			e.print();
		}
	}
	cout << year << "�� " << month << "�� " << day << "��" << endl;
}
