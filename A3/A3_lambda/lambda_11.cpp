#include <iostream>

int main(){
	int* pFirst = new int(5);
	auto addToThePointerValue = [&pFirst](int second)
		{return *pFirst + second;};
	std::cout << addToThePointerValue(10) << std::endl; // writes 15
	delete pFirst;
	return 0;
}
