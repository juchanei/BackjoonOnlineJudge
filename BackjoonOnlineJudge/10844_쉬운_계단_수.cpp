#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;
const ull MOD = 1000000000;

int length;
vector<vector<ull> > cache;

ull dfs(int here, int currentNumber)
{
	if (here == length) {
		return 1;
	}
	ull& ret = cache[here][currentNumber];
	if (-1 != ret) {
		return ret;
	}

	ull sum = 0;
	if (0 <= currentNumber - 1) {
		sum += dfs(here + 1, currentNumber - 1) % MOD;
	}
	if (currentNumber + 1 <= 9) {
		sum += dfs(here + 1, currentNumber + 1) % MOD;
	}
	sum %= MOD;

	ret = sum;
	return sum;
}

int main()
{
	cin >> length;
	cache.assign(length + 1, vector<ull>(10, -1));
	ull sum = 0;
	for (int i = 1; i <= 9; ++i) {
		sum += dfs(1, i);
		sum %= MOD;
	}

	cout << sum << endl;

	return 0;
}