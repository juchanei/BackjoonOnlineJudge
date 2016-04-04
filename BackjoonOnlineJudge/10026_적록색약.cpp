#include <iostream>
#include <vector>
using namespace std;

const int DIR[4][2] = {
	0, -1,
	0, 1,
	-1, 0,
	1, 0
};

int mapSize;
vector<vector<char> > map;
vector<vector<int> > visited;

void dfs(int xx, int yy, char color, int count)
{
	visited[yy][xx] = count;

	for (int i = 0; i < 4; ++i) {
		int nextx = xx + DIR[i][0];
		int nexty = yy + DIR[i][1];
		if (0 == visited[nexty][nextx] && color == map[nexty][nextx]) {
			dfs(nextx, nexty, color, count);
		}
	}

}

void dfs2(int xx, int yy, char color1, char color2, int count)
{
	visited[yy][xx] = count;

	for (int i = 0; i < 4; ++i) {
		int nextx = xx + DIR[i][0];
		int nexty = yy + DIR[i][1];
		if (0 == visited[nexty][nextx] &&
			(color1 == map[nexty][nextx] || color2 == map[nexty][nextx])) {
			dfs2(nextx, nexty, color1, color2, count);
		}
	}

}

int main()
{
	cin >> mapSize;

	map.assign(mapSize + 2, vector<char>(mapSize + 2, '_'));
	visited.assign(mapSize + 2, vector<int>(mapSize + 2, 0));
	for (int i = 1; i < map.size() - 1; ++i) {
		for (int j = 1; j < map.size() - 1; ++j) {
			cin >> map[i][j];
		}
	}

	int count1 = 1;
	for (int i = 1; i < map.size() - 1; ++i) {
		for (int j = 1; j < map.size() - 1; ++j) {
			if (0 == visited[i][j]) {
				char color = map[i][j];
				dfs(j, i, color, count1);
				count1++;
			}
		}
	}

	visited.assign(mapSize + 2, vector<int>(mapSize + 2, 0));

	int count2 = 1;
	for (int i = 1; i < map.size() - 1; ++i) {
		for (int j = 1; j < map.size() - 1; ++j) {
			if (0 == visited[i][j]) {
				char color1 = map[i][j];
				char color2 = 0;
				if (color1 == 'R') color2 = 'G';
				if (color1 == 'G') color2 = 'R';
				dfs2(j, i, color1, color2, count2);
				count2++;
			}
		}
	}

	cout << count1 - 1 << " " << count2 - 1 << endl;

	return 0;
}