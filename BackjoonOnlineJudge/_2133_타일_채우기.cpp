#include <iostream>
#include <vector>
using namespace std;

int length;
vector<int> cache;

int recu(int here)
{
	if (here == length) {
		return 1;
	}
	else if (length < here) {
		return 0;
	}
	int& ret = cache[here];
	if (-1 != ret) {
		return ret;
	}

	int sum = 0;
	sum += recu(here + 2);
	sum += recu(here + 2);
	sum += recu(here + 2);
	sum += recu(here + 4);
	sum += recu(here + 4);

	ret = sum;
	return sum;
}

int main()
{
	cin >> length;
	cache.assign(length + 1, -1);
	cout << recu(0) << endl;

	return 0;
}