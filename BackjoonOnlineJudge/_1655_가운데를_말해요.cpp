#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int main()
{
	int nNumber;
	cin >> nNumber;

	vector<int> numbers;
	for (int i = 1; i <= nNumber; ++i)
	{
		int newNuber;
		cin >> newNuber;

		numbers.push_back(newNuber);
		sort(numbers.begin(), numbers.end());
		
		if (0 == i % 2){
			printf("%d\n", (numbers[i / 2 - 1] < numbers[i / 2] ? numbers[i / 2 - 1] : numbers[i / 2]));
		}
		else{
			printf("%d\n", numbers[i / 2]);
		}
	}

	return 0;
}