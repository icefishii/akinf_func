#include <iostream>

int main(){
	int first = 5;
	int second = 6;
	int third = 7;
	int fourth = 8;
	int fifth = 9;

	auto addTheFiveWithDefaultReferenceCapture = [&]()
		{return first + second + third + fourth + fifth;};
	std::cout << addTheFiveWithDefaultReferenceCapture() << std::endl; // writes 35
	return 0;
}
