#include <iostream>
#include <vector>
using namespace std;

const int DIR[3][2] = {
	0, 1,
	1, 0,
	1, 1
};

vector<vector<int> > map;
vector<vector<int> > cache;

int max(int a, int b)
{
	return a < b ? b : a;
}

int dfs(int xx, int yy)
{
	if (map.size() - 2 == yy && map[yy].size() - 2 == xx) {
		return map[yy][xx];
	}
	int& ret = cache[yy][xx];
	if (-1 != ret) {
		return ret;
	}

	int maxValue = 0;
	for (int i = 0; i < 3; ++i) {
		if (-1 != map[yy + DIR[i][1]][xx + DIR[i][0]]) {
			maxValue = max(maxValue, dfs(xx + DIR[i][0], yy + DIR[i][1]) + map[yy][xx]);
		}
	}

	ret = maxValue;
	return maxValue;
}

int main()
{
	int height, width;
	cin >> height >> width;
	map.assign(height + 2, vector<int>(width + 2, -1));
	cache.assign(height + 2, vector<int>(width + 2, -1));
	for (int i = 1; i < map.size() - 1; ++i) {
		for (int j = 1; j < map[i].size() - 1; ++j) {
			cin >> map[i][j];
		}
	}

	cout << dfs(1, 1) << endl;

	return 0;
}