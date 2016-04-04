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

void dfs(int xx, int yy, int count)
{
	visited[yy][xx] = count;

	for (int i = 0; i < 4; ++i) {
		if (count < visited[yy + DIR[i][1]][xx + DIR[i][0]]){
			if (1 == map[yy + DIR[i][1]][xx + DIR[i][0]]) {
				dfs(xx + DIR[i][0], yy + DIR[i][1], count);
			}
			else if (0 == map[yy + DIR[i][1]][xx + DIR[i][0]]) {
				dfs(xx + DIR[i][0], yy + DIR[i][1], count + 1);
			}
		}
	}
}

int main()
{
	cin >> mapSize;

	map.assign(mapSize + 2, vector<int>(mapSize + 2, -1));
	visited.assign(mapSize + 2, vector<int>(mapSize + 2, INF));
	for (int i = 1; i < map.size() - 1; ++i) {
		scanf("\n");
		for (int j = 1; j < map[0].size() - 1; ++j) {
			char temp;
			scanf("%c", &temp);
			map[i][j] = temp - '0';
		}
	}

	dfs(1, 1, 0);

	cout << visited[mapSize][mapSize] << endl;

	return 0;
}