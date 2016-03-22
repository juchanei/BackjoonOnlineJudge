#include <iostream>
using namespace std;

int find(int number, int index)
{
	int result = 0;
	for (int i = 0; i <= index; ++i){
		result = number % 10;
		number /= 10;
	}
	return result;
}

int main()
{
	int nNumber, targetIndex;
	cin >> nNumber >> targetIndex;

	int currentIndex = 0;
	int indexUnit = 1;
	int digit = 10;

	int theNumber = 0;
	int innerIndex = 0;
	for (int i = 1; i <= nNumber; i++)
	{
		if (0 != (i / digit)){
			indexUnit++;
			digit *= 10;
		}
		currentIndex += indexUnit;
		if (targetIndex <= currentIndex){
			theNumber = i;
			innerIndex = currentIndex - targetIndex;
			break;
		}
	}

	if (theNumber == 0){
		cout << -1 << endl;
		return 0;
	}
	cout << find(theNumber, innerIndex) << endl;;

	return 0;
}