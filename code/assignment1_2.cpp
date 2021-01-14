#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Time {
	int hour;
	int minute;
	int second;
public:
	Time() : Time(0, 0, 0) {}
	Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

	void timePrn() const {
		cout << hour << "�� " << minute << "�� " << second << "��" << endl;
	}

	int getHour() const {
		return hour;
	}

	int getMinute() const {
		return minute;
	}

	int getSecond() const {
		return second;
	}

	void setHour(int hour) {
		this->hour = hour;
	}

	void setMinute(int minute) {
		this->minute = minute;
	}

	void setSecond(int second) {
		this->second = second;
	}
};

bool timeCompare(Time& t1, Time& t2) {
	return t1.getHour() < t2.getHour();
}

int main() {
	int count;
	cout << "�ð� ����? ";
	cin >> count;
	vector<Time> times;
	for (int i = 0; i < count; ++i) {
		int hour, minute, second;
		cout << "'�� �� ��' ������ �Է�: ";
		cin >> hour >> minute >> second;
		times.push_back(Time(hour, minute, second));
	}
	sort(times.begin(), times.end(), timeCompare);
	for (auto time : times) {
		time.timePrn();
	}
	return 0;
}
