#include <iostream>
#include <vector>
using namespace std;

enum Status { BOTH = 0, LEFT, RIGHT };
const int MOD = 9901;

int length;
vector<vector<int> > cache;

int recu(int here, Status isAvailable)
{
	if (length == here) {
		return 1;
	}
	int& ret = cache[here][isAvailable];
	if (-1 != ret) {
		return ret;
	}

	int sum = 0;
	if (isAvailable == BOTH) {
		sum += recu(here + 1, RIGHT);
		sum += recu(here + 1, LEFT);
		sum %= MOD;
	}
	else if (isAvailable == LEFT) {
		sum += recu(here + 1, RIGHT);
		sum %= MOD;
	}
	else if (isAvailable == RIGHT) {
		sum += recu(here + 1, LEFT);
		sum %= MOD;
	}
	sum += recu(here + 1, BOTH);
	sum %= MOD;

	ret = sum;
	return sum;
}

int main()
{
	cin >> length;
	cache.assign(length, vector<int>(3, -1));
	cout << recu(0, BOTH) << endl;
	return  0;
}