#include <cstring>
#include <iostream>

using namespace std;

class Game {
	char* name;
	int power;
	static int stadium;
public:
	Game() {
		name = new char[20];
		strcpy(name, "noname");
		power = 0;
		stadium++;
	}

	Game(const char* name, int power) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->power = power;
		stadium++;
	}

	~Game() {
		std::cout << "소멸자 실행 " << name << endl;
		delete[] name;
		stadium--;
	}

	Game(const Game& game) : power(game.power) {
		name = new char[strlen(game.name) + 1];
		strcpy(name, game.name);
		stadium++;
	}


	void setPower(int power) {
		this->power = power;
	}

	int getPower() const {
		return power;
	}

	void output() const {
		cout << "player" << stadium << ":" << name << ",(" << power << ")" << endl;
	}

	static void printStatus() {
		cout << "현재 " << stadium << "개의 경기장 오픈 중!" << endl;
	}
};

int Game::stadium = 0;


int main() {
	Game::printStatus();
	Game player1;
	player1.output();
	Game player2("Jung", 100);
	player2.output();
	Game player3(player2);
	player3.output();
	Game::printStatus();
}
