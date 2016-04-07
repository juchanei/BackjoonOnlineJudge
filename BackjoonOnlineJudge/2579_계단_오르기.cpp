#include <iostream>
#include <vector>
using namespace std;

vector<int> stairs;
vector<vector<int> > cache;

int max(int a, int b)
{
	return a < b ? b : a;
}

int recu(int here, int nContinuousStep)
{
	if (here <= 0) {
		return 0;
	}
	int& ret = cache[here][nContinuousStep];
	if (-1 != ret) {
		return ret;
	}

	int maxValue = 0;
	if (nContinuousStep < 2) {
		maxValue = max(maxValue, recu(here - 1, nContinuousStep + 1) + stairs[here]);
	}
	maxValue = max(maxValue, recu(here - 2, 1) + stairs[here]);

	ret = maxValue;
	return maxValue;
}

int main()
{
	int nStair;
	cin >> nStair;

	stairs.assign(nStair + 1, 0);
	for (int i = 1; i < stairs.size(); ++i) {
		cin >> stairs[i];
	}

	cache.assign(nStair + 1, vector<int>(3, -1));
	cout << recu(stairs.size() - 1, 1) << endl;

	return 0;
}