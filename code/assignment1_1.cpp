#include <iostream>

class Time {
	int hour;
	int minute;
	int second;
public:
	Time() : Time(0, 0, 0) {}
	Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

	void timePrn() const {
		std::cout << hour << "시 " << minute << "분 " << second << "초" << std::endl;
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

int main() {
	Time t1;
	Time t2(13, 27, 6);
	t2.timePrn();
	std::cout << "t2 시계의 시간이 " << t2.getHour() << "에서";
	t2.setHour(15);
	std::cout << t2.getHour() << "로 변경됨" << std::endl;
	t1.timePrn();
	t2.timePrn();
	return 0;
}
