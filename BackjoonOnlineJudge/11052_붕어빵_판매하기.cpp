#include <iostream>
#include <vector>
using namespace std;

vector<int> breads;
vector<vector<int> > cache;

int max(int a, int b)
{
	return a < b ? b : a;
}

int lis(int here, int count)
{
	if (breads.size() == here) {
		return 0;
	}
	int& ret = cache[here][count];
	if (-1 != ret) {
		return ret;
	}

	int maxValue = 0;
	if (0 <= count - here) {
		maxValue = max(maxValue, lis(here, count - here) + breads[here]);
	}
	maxValue = max(maxValue, lis(here + 1, count));

	ret = maxValue;
	return maxValue;
}

int main()
{
	int nBread;
	cin >> nBread;
	breads.assign(nBread + 1, 0);
	cache.assign(nBread + 1, vector<int>(nBread + 1, -1));
	for (int i = 1; i < breads.size(); ++i) {
		cin >> breads[i];
	}

	cout << lis(1, nBread) << endl;

	return 0;
}