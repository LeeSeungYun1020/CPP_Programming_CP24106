#include <iostream>

int main() {
	double fTemp, cTemp;
	std::cout << " >> ";
	std::cin >> fTemp;
	cTemp = (fTemp - 32) * 5 / 9;
	std::cout << "����" << cTemp << "��" << std::endl;
}