#include <iostream>
#include <vector>
using namespace std;

vector<int> numbers;
vector<int> cache;

int max(int a, int b)
{
	return a < b ? b : a;
}

int lis(int here)
{
	int& ret = cache[here];
	if (-1 != ret) {
		return ret;
	}

	int maxValue = 1;
	for (int i = here + 1; i < numbers.size(); ++i) {
		if (numbers[here] < numbers[i]) {
			maxValue = max(maxValue, lis(i) + 1);
		}
	}

	ret = maxValue;
	return maxValue;
}

int main()
{
	int nNumber;
	cin >> nNumber;
	numbers.assign(nNumber, 0);
	cache.assign(nNumber, -1);
	for (int i = 0; i < numbers.size(); ++i) {
		cin >> numbers[i];
	}

	int maxValue = 0;
	for (int i = 0; i < numbers.size(); ++i) {
		maxValue = max(maxValue, lis(i));
	}
	cout << maxValue << endl;

	return 0;
}