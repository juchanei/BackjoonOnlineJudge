#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;

int targetPrice;
vector<int> prices;
vector<int> cache;

int min(int a, int b)
{
	return a < b ? a : b;
}

int recu(int currentPrice)
{
	if (targetPrice == currentPrice) {
		return 0;
	}
	else if (targetPrice <= currentPrice) {
		return INF;
	}
	int& ret = cache[currentPrice];
	if (-1 != ret) {
		return ret;
	}

	int minValue = INF;
	for (int i = 0; i < prices.size(); ++i) {
		minValue = min(minValue, recu(currentPrice + prices[i]) + 1);
	}

	ret = minValue;
	return minValue;
}

int main()
{
	int nCoinType;
	cin >> nCoinType >> targetPrice;
	prices.assign(nCoinType, 0);
	for (int i = 0; i < prices.size(); ++i) {
		cin >> prices[i];
	}

	cache.assign(targetPrice, -1);
	int minValue = INF;
	for (int i = 0; i < prices.size(); ++i) {
		minValue = min(minValue, recu(prices[i]) + 1);
	}

	if (INF == minValue) {
		cout << -1 << endl;
		return 0;
	}
	cout << minValue << endl;

	return 0;
}