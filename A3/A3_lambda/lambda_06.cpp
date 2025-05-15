#include <iostream>

int main(){
	int first = 5;
	int second = 6;
	int third = 7;
	int fourth = 8;
	int fifth = 9;

	auto addTheFive = [&first, &second, &third, &fourth, &fifth]()
		{return first + second + third + fourth + fifth;};
	std::cout << addTheFive() << std::endl; // writes 35
	return 0;
}
