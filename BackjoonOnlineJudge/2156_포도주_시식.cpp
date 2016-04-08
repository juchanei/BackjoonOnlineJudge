#include <iostream>
#include <vector>
using namespace std;

vector<int> glasses;
vector<vector<int> > cache;

int max(int a, int b)
{
	return a < b ? b : a;
}

int recu(int here, int nContinuousGlass)
{
	if (here == glasses.size()) {
		return 0;
	}
	int& ret = cache[here][nContinuousGlass];
	if (-1 != ret) {
		return ret;
	}

	int maxValue = 0;
	if (nContinuousGlass < 2) {
		maxValue = max(maxValue, recu(here + 1, nContinuousGlass + 1) + glasses[here]);
	}
	maxValue = max(maxValue, recu(here + 1, 0));

	ret = maxValue;
	return maxValue;
}


int main()
{
	int nGlass;
	cin >> nGlass;
	glasses.assign(nGlass, 0);
	for (int i = 0; i < glasses.size(); ++i) {
		cin >> glasses[i];
	}

	cache.assign(glasses.size(), vector<int>(3, -1));
	cout << recu(0, 0) << endl;

	return 0;
}