#include <iostream>

int main(){
	int first = 5;
	int second = 6;
	int third = 7;
	int fourth = 8;
	int fifth = 9;

	auto addTheFiveWithDefaultValueCapture = [=]()
		{return first + second + third + fourth + fifth;};
  std::cout << addTheFiveWithDefaultValueCapture() << std::endl; // writes
	return 0;
}
