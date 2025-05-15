#include <iostream>

int main(){
	int first = 5;
  auto addToFirst = [first](int second){ return first + second;};
	std::cout << addToFirst(10) << std::endl;
	return 0;
}
