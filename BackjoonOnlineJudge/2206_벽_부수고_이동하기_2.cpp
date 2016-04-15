#include <iostream>
#include <vector>
using namespace std;

const int DIR[4][2] = {
	0, 1,
	1, 0,
	0, -1,
	-1, 0
};

vector<vector<int> > map;
vector<vector<bool> > visited;

int bestResult = 987654321;
void dfs(int xx, int yy, int count, bool wallFlag)
{
	if (bestResult <= count) {
		return;
	}
	if (yy == map.size() - 2 && xx == map[yy].size() - 2) {
		if (count < bestResult) {
			bestResult = count;
			return;
		}
	}
	visited[yy][xx] = 1;

	for (int i = 0; i < 4; i < ++i) {
		if (0 == visited[yy + DIR[i][1]][xx + DIR[i][0]]) {
			if (0 == map[yy + DIR[i][1]][xx + DIR[i][0]]) {
				dfs(xx + DIR[i][0], yy + DIR[i][1], count + 1, wallFlag);
			}
			if (1 == map[yy + DIR[i][1]][xx + DIR[i][0]] && true == wallFlag) {
				dfs(xx + DIR[i][0], yy + DIR[i][1], count + 1, false);
			}
		}
	}

	visited[yy][xx] = 0;
}

int main()
{
	int height, width;
	cin >> height >> width;
	map.assign(height + 2, vector<int>(width + 2, 8));
	visited.assign(height + 2, vector<bool>(width + 2, 0));
	for (int i = 1; i < map.size() - 1; ++i) {
		for (int j = 1; j < map[i].size() - 1; ++j) {
			char temp;
			cin >> temp;
			map[i][j] = temp - '0';
		}
	}

	dfs(1, 1, 1, true);
	if (987654321 == bestResult) {
		cout << -1 << endl;
		return 0;
	}
	cout << bestResult << endl;

	return 0;
}