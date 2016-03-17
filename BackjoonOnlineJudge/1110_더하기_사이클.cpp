#include <iostream>
using namespace std;

int main()
{
	int theNumber = 0;
	cin >> theNumber;

	int theSum = 0;
	int nextNumber = theNumber;
	int count = 0;
	while (1){
		theSum = nextNumber / 10 + nextNumber % 10;
		nextNumber = (nextNumber % 10) * 10 + theSum % 10;
		++count;
		if (nextNumber == theNumber) break;
	}

	cout << count << endl;

	return 0;
}