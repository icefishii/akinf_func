#include <iostream>

int main(){
	auto add = [](int first, int second) { return first + second;};
	std::cout << add(1,2) << std::endl;
	return 0;
}
