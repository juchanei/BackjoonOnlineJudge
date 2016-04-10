#include <iostream>
#include <vector>
using namespace std;

const int NOT_VISITED = 987654321;
vector<int> numbers;
vector<vector<int> > cache;

int max(int a, int b)
{
	return a < b ? b : a;
}

int recu(int here, int state)
{
	if (here == numbers.size()) {
		return 0;
	}
	int& ret = cache[here][state];
	if (NOT_VISITED != ret) {
		return ret;
	}

	int maxValue = 0;
	if (0 == state) {
		maxValue = max(maxValue, recu(here + 1, 0));
		maxValue = max(maxValue, recu(here + 1, 1) + numbers[here]);
	}
	else if (1 == state) {
		maxValue = max(maxValue, recu(here + 1, 1) + numbers[here]);
		maxValue = max(maxValue, recu(here + 1, 2));
	}
	else if (2 == state) {
		maxValue = max(maxValue, recu(here + 1, 2));
	}
	 
	ret = maxValue;
	return maxValue;
}

int main()
{
	int nNumber;
	cin >> nNumber;
	numbers.assign(nNumber, 0);
	for (int i = 0; i < numbers.size(); ++i) {
		cin >> numbers[i];
	}

	cache.assign(nNumber, vector<int>(3, NOT_VISITED));
	int ret = recu(0, 0);
	if (0 != ret) {
		cout << ret << endl;
		return 0;
	}

	int maxValue = -987654321;
	for (int i = 0; i < numbers.size(); ++i) {
		maxValue = max(maxValue, numbers[i]);
	}
	cout << maxValue << endl;

	return 0;
}