#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int DIR[4][2] = {
	0, -1,
	0, 1,
	-1, 0,
	1, 0
};
const int INF = 987654321;

int mapSize;
vector<vector<int> > map;
vector<vector<int> > visited;

int minValue = INF;
void dfs(int x, int y, int count)
{
	if (minValue < count) {
		return;
	}
	if (x == mapSize && y == mapSize) {
		if (count < minValue) {
			minValue = count;
		}
	}

	visited[y][x] = 1;

	for (int i = 0; i < 4; ++i) {
		if (0 == visited[y + DIR[i][1]][x + DIR[i][0]]) {
			if (0 == map[y + DIR[i][1]][x + DIR[i][0]]) {
				dfs(x + DIR[i][0], y + DIR[i][1], count + 1);
			}
			else if (1 == map[y + DIR[i][1]][x + DIR[i][0]]) {
				dfs(x + DIR[i][0], y + DIR[i][1], count);
			}
		}
	}

	visited[y][x] = 0;
}

int main()
{
	cin >> mapSize;

	map.assign(mapSize + 2, vector<int>(mapSize + 2, -1));
	visited.assign(mapSize + 2, vector<int>(mapSize + 2, 0));
	for (int i = 1; i < map.size() - 1; ++i) {
		scanf("\n");
		for (int j = 1; j < map[0].size() - 1; ++j) {
			char temp;
			scanf("%c", &temp);
			map[i][j] = temp - '0';
		}
	}

	dfs(1, 1, 0);
	cout << minValue << endl;

	return 0;
}