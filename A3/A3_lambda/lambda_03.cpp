#include <iostream>

int main(){
	int first = 5;
	auto addToFirst = [](int second){ return first + second;};
	// error: variable 'first' cannot be implicitly captured
	std::cout << add(10) << std::endl;
	return 0;
}
