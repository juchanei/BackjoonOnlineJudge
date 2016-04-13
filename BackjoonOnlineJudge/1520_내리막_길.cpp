#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
const int DIR[4][2] = {
	0, -1, 
	0, 1, 
	-1, 0, 
	1, 0
};

int height, width;
vector<vector<int> > map;
vector<vector<int> > cache;

int dfs(const int xx, const int yy)
{
	if (xx == width && yy == height) {
		return 1;
	}
	int& ret = cache[yy][xx];
	if (-1 != ret) {
		return ret;
	}

	int sum = 0;
	for (int i = 0; i < 4; ++i) {
		if (map[yy + DIR[i][1]][xx + DIR[i][0]] < map[yy][xx]) {
			sum += dfs(xx + DIR[i][0], yy + DIR[i][1]);
		}
	}

	ret = sum;
	return sum;
}

int main()
{
	cin >> height >> width;

	map.assign(height + 2, vector<int>(width + 2, INF));
	cache.assign(height + 2, vector<int>(width + 2, -1));
	for (int i = 1; i < map.size() - 1; ++i) {
		for (int j = 1; j < map[i].size() - 1; ++j) {
			cin >> map[i][j];
		}
	}
	
	cout << dfs(1,1) << endl;

	return 0;
}