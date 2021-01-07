#include <iostream>

using namespace std;

class Animal {
	char* name;
public:
	Animal() {
		name = new char[16];
		strcpy(name, "animal");
	}

	Animal(char* name) {
		int len = strlen(name) + 1;
		if (len < 16) {
			len = 16;
		}
		this->name = new char[len];
		strcpy(this->name, name);
	}

	Animal(const Animal& copy) {
		int len = strlen(copy.name) + 1;
		if (len < 16) {
			len = 16;
		}
		name = new char[len];
		strcpy(name, copy.name);
	}

	virtual ~Animal() {
		cout << "¼Ò¸ê" << name << endl;
		delete[] name;
	}

	virtual void talk() {
		cout << "Animal something" << endl;
	}

	void speak() {
		cout << "Animal " << name << ": ";
		talk();
	}

	char* getName() const {
		return name;
	}

	void setName(char* name) {
		delete[] (this->name);
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
};

class Dog : public Animal {
public:
	Dog(): Animal() {}
	Dog(char* name): Animal(name) {}

	void talk() {
		cout << "woof" << endl;
	}
};

class Cat : public Animal {
public:
	Cat() : Animal() {
		char n[7] = "Kitty";
		setName(n);
	}

	Cat(char* name): Animal(name) {}

	void talk() {
		cout << "meow" << endl;
	}

	void speak() {
		cout << getName() << ": ";
		talk();
	}
};

class Cow : public Animal {
public:
	void talk() {
		cout << "something" << endl;
	}
};

class Pig : public Animal {
public:
	Pig() {}

	void talk() {
		cout << "oink" << endl;
	}

	void speak() {
		cout << "PIG ";
		Animal::speak();
	}
};


int main() {
	Dog dog;
	Cat* cat = new Cat;
	Cow cow;
	Pig pig;
	Animal catAni(*cat);
	Animal* animalArr[5] = {
		&dog, cat, &cow, &pig, &catAni
	};
	/*
	for (auto& animal : animalArr) {
		animal->talk();
	}
	*/
	cat->talk();
	catAni.talk();

	cat->speak();
	catAni.speak();
	
	pig.talk();
	animalArr[3]->talk();

	pig.speak();
	animalArr[3]->speak();

	cat = (Cat*)animalArr[4];
	cat->speak();
	animalArr[4]->speak();
}
