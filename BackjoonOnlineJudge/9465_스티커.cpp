#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

enum AvailableSticker {TOP = 0, BOTTOM, BOTH};
vector<vector<int> > stickers;
vector<vector<int> > cache;

int max(int a, int b)
{
	return a < b ? b : a;
}

int recu(int here, AvailableSticker status)
{
	if (stickers.size() <= here) {
		return 0;
	}
	int& ret = cache[status][here];
	if (-1 != ret) {
		return ret;
	}

	int maxValue = 0;
	if (status == BOTH) {
		maxValue = max(maxValue, recu(here + 1, BOTTOM) + stickers[here][TOP]);
		maxValue = max(maxValue, recu(here + 1, TOP) + stickers[here][BOTTOM]);
	}
	else if (status == TOP) {
		maxValue = max(maxValue, recu(here + 1, BOTTOM) + stickers[here][status]);
	}
	else if (status == BOTTOM) {
		maxValue = max(maxValue, recu(here + 1, TOP) + stickers[here][status]);
	}
	maxValue = max(maxValue, recu(here + 1, BOTH));

	ret = maxValue;
	return maxValue;
}

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		int nStickerLine;
		cin >> nStickerLine;
		stickers.assign(nStickerLine, vector<int>(2, 0));
		for (int i = 0; i < stickers.size(); ++i) {
			scanf("%d ", &stickers[i][0]);
		}
		for (int i = 0; i < stickers.size(); ++i) {
			scanf("%d ", &stickers[i][1]);
		}
		
		cache.assign(3, vector<int>(stickers.size(), -1));
		cout << recu(0, BOTH) << endl;
	}

	return 0;
}