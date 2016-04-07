#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

int nn;
vector<vector<ull> > cache;

ull recu(int here, int isOne)
{
	if (nn == here) {
		return 1;
	}
	ull& ret = cache[here][isOne];
	if (-1 != ret) {
		return ret;
	}

	ull sum = 0;
	if (0 == isOne) {
		sum += recu(here + 1, 1);
	}
	sum += recu(here + 1, 0);

	ret = sum;
	return sum;
}

int main()
{
	cin >> nn;
	cache.assign(nn, vector<ull>(2, -1));
	cout << recu(1, 1) << endl;

	return 0;
}