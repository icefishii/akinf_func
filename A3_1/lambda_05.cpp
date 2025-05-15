#include <iostream>

int main(){
	int first = 5;
	auto addToFirstByReference = [&first](int second){ return first + second;};
  std::cout << addToFirstByReference(10) << std::endl; // writes 15
	return 0;
}
