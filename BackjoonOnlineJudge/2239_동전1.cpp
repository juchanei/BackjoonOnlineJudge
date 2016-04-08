#include <iostream>
#include <vector>
using namespace std;

int targetPrice;
vector<int> prices;
vector<vector<int> > cache;

int recu(int currentPrice, int prevPriceIndex)
{
	if (currentPrice == targetPrice) {
		return 1;
	}
	else if (targetPrice < currentPrice) {
		return 0;
	}
	int& ret = cache[currentPrice][prevPriceIndex];
	if (-1 != ret) {
		return ret;
	}

	int sum = 0;
	for (int i = prevPriceIndex; i < prices.size(); ++i) {
		sum += recu(currentPrice + prices[i], i);
	}

	ret = sum;
	return sum;
}

int main()
{
	int nCoinType;
	cin >> nCoinType >> targetPrice;
	prices.assign(nCoinType, 0);
	for (int i = 0; i < prices.size(); ++i) {
		cin >> prices[i];
	}

	cache.assign(targetPrice, vector<int>(prices.size(), -1));
	cout << recu(0, 0) << endl;

	return 0;
}