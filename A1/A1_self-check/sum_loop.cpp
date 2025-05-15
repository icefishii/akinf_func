#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


int sub_sumWithFunctionalLoops(const vector<int>& numbers) {
    vector<int> oddNumbers, evenNumbers;
    int oddSum = 0, evenSum = 0, totalSum = 0;
    copy_if(numbers.begin(), numbers.end(), back_inserter(oddNumbers), [](int n) { return n % 2 != 0; });
    copy_if(numbers.begin(), numbers.end(), back_inserter(evenNumbers), [](int n) { return n % 2 == 0; });
    oddSum = accumulate(oddNumbers.begin(), oddNumbers.end(), 0);
    evenSum = accumulate(evenNumbers.begin(), evenNumbers.end(), 0);
    totalSum = oddSum - evenSum;
    return totalSum;
}

int main() {
    vector<int> numbers = {8, 3, 1,};
    cout << "Total (odd added, even subtracted): " << sub_sumWithFunctionalLoops(numbers) << endl;

    return 0;
}