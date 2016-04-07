#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
vector<int> cache;

int min(int a, int b)
{
	return a < b ? a : b;
}

int recu(int number)
{
	if (1 == number) {
		return 0;
	}
	int& ret = cache[number];
	if (-1 != ret) {
		return ret;
	}

	int minValue = INF;
	if (0 == number % 3) {
		minValue = min(minValue, recu(number / 3) + 1);
	}
	if (0 == number % 2) {
		minValue = min(minValue, recu(number / 2) + 1);
	}
	if (0 < number) {
		minValue = min(minValue, recu(number - 1) + 1);
	}

	ret = minValue;
	return minValue;
}

int main()
{
	int nn;
	cin >> nn;
	cache.assign(nn + 1, -1);
	cout << recu(nn) << endl;

	return 0;
}