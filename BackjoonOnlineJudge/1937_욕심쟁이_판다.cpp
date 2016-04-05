#include <iostream>
#include <vector>
using namespace std;

const int DIR[4][2] = {
	0, -1,
	0, 1,
	-1, 0,
	1, 0
};

vector<vector<int> > map;
vector<vector<int> > cache;

int max(int a, int b)
{
	return a < b ? b : a;
}

int dfs(int xx, int yy)
{
	int& ret = cache[yy][xx];
	if (-1 != ret) {
		return ret;
	}

	int maxValue = 0;
	for (int i = 0; i < 4; ++i) {
		if (map[yy][xx] < map[yy + DIR[i][1]][xx + DIR[i][0]]) {
			maxValue = max(maxValue, dfs(xx + DIR[i][0], yy + DIR[i][1]) + 1);
		}
	}

	ret = maxValue;
	return maxValue;
}

int main()
{
	int mapSize;
	cin >> mapSize;

	map.assign(mapSize + 2, vector<int>(mapSize + 2, 0));
	cache.assign(mapSize + 2, vector<int>(mapSize + 2, -1));
	for (int i = 1; i < map.size() - 1; ++i) {
		for (int j = 1; j < map[0].size() - 1; ++j) {
			cin >> map[i][j];
		}
	}

	int maxValue = 0;
	for (int i = 1; i < map.size() - 1; ++i) {
		for (int j = 1; j < map[0].size() - 1; ++j) {
			if (-1 == cache[i][j]) {
				maxValue = max(maxValue, dfs(j, i) + 1);
			}
			else {
				maxValue = max(maxValue, cache[i][j] + 1);
			}
		}
	}

	cout << maxValue << endl;

	return 0;
}