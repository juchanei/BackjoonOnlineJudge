#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int DIR[4][2] = {
	0, -1,
	0, 1,
	-1, 0,
	1, 0
};

struct Node
{
	int x;
	int y;
	int time;
	Node(int x, int y, int time) :x(x), y(y), time(time) {}
	Node() :x(0), y(0), time(0) {}
};

vector<vector<char> > map;
vector<vector<char> > waterMap;
vector<vector<int> > waterTime;

void makeWaterMap()
{
	int height = waterMap.size() - 1;
	int width = waterMap[0].size() - 1;
	int iter = height < width ? width : height;

	for (int h = 0; h < iter; ++h) {
		for (int i = 1; i < waterMap.size() - 1; ++i) {
			for (int j = 1; j < waterMap[i].size() - 1; ++j) {
				if ('*' == waterMap[i][j] && h == waterTime[i][j]) {

					for (int k = 0; k < 4; ++k) {
						if ('.' == waterMap[i + DIR[k][1]][j + DIR[k][0]] ||
							'S' == waterMap[i + DIR[k][1]][j + DIR[k][0]]) {
							waterTime[i + DIR[k][1]][j + DIR[k][0]] = waterTime[i][j] + 1;
							waterMap[i + DIR[k][1]][j + DIR[k][0]] = '*';
						}
					}

				}
			}
		}
	}
}

int bfs(int startx, int starty, int destx, int desty)
{
	vector<vector<int> > visited(map.size(), vector<int>(map[0].size(), 0));
	queue<Node> qq;
	Node startNode(startx, starty, 0);
	qq.push(startNode);
	visited[startNode.y][startNode.x] = 1;

	while (!qq.empty()) {
		Node here = qq.front();
		qq.pop();

		if (here.x == destx && here.y == desty) {
			return here.time;
		}

		for (int i = 0; i < 4; ++i) {
			Node next(here.x + DIR[i][0], here.y + DIR[i][1], here.time + 1);
			if (('.' == map[next.y][next.x] || 'D' == map[next.y][next.x]) &&
				(next.time < waterTime[next.y][next.x] || 0 == waterTime[next.y][next.x]) &&
				0 == visited[next.y][next.x]) {

				qq.push(next);
				visited[next.y][next.x] = 1;
			}
		}
	}
	
	return 0;
}

void findStartDest(int& startx, int& starty, int& destx, int& desty)
{
	for (int i = 1; i < map.size() - 1; ++i) {
		for (int j = 1; j < map[i].size() - 1; ++j) {
			if ('S' == map[i][j]) {
				startx = j;
				starty = i;
			}
			if ('D' == map[i][j]) {
				destx = j;
				desty = i;
			}
		}
	}
}

int main()
{
	int height, width;
	cin >> height >> width;

	map.assign(height + 2, vector<char>(width + 2, 'X'));
	waterTime.assign(height + 2, vector<int>(width + 2, 0));
	for (int i = 1; i < map.size() - 1; ++i) {
		for (int j = 1; j < map[i].size() - 1; ++j) {
			cin >> map[i][j];
		}
	}
	waterMap = map;
	makeWaterMap();

	int startx, starty, destx, desty;
	findStartDest(startx, starty, destx, desty);

	int result = bfs(startx, starty, destx, desty);
	if (0 == result) {
		cout << "KAKTUS" << endl;
		return 0;
	}

	cout << result << endl;

	return 0;
}