#include <iostream>
#include <vector>
#include <queue>
using namespace std;

enum Command {NOT = 0, GO, TURN};

struct Node
{
	int x;
	int y;
	int dir;
	int count;
	Command preCommand;
	Node(int x, int y, int dir, int count, Command preCommand) : x(x), y(y), dir(dir), count(count), preCommand(preCommand) {}
	Node() : x(0), y(0), dir(0), count(0), preCommand(NOT) {}
};

const int INF = 9876541321;
const int DIR[4][2] = {
	1, 0,
	-1, 0,
	0, 1,
	0, -1
};

int height, width;
int startx, starty, startdir;
int endx, endy, enddir;
vector<vector<int> > map;

int min(int a, int b)
{
	return a < b ? a : b;
}

int turn(int currentDir, int dir)	
{
	switch (currentDir) {
	case 1:
		if (0 == dir) {
			return 3;
		}
		else if (1 == dir){
			return 4;
		}
		else {
			return 2;
		}
	case 2:
		if (0 == dir) {
			return 4;
		}
		else if (1 == dir) {
			return 3;
		}
		else {
			return 1;
		}
	case 3:
		if (0 == dir) {
			return 1;
		}
		else if (1 == dir) {
			return 2;
		}
		else {
			return 4;
		}
	case 4:
		if (0 == dir) {
			return 2;
		}
		else if (1 == dir) {
			return 1;
		}
		else {
			return 3;
		}
	}
}

int bfs()
{
	vector<vector<int> > visited(height + 2, vector<int>(width + 2, 0));
	Node startNode(startx, starty, startdir, 0, NOT);
	queue<Node> qq;
	qq.push(startNode);
	visited[startNode.y][startNode.x] = 1;

	while (!qq.empty()) {
		Node here = qq.front();
		qq.pop();

		if (here.x == endx && here.y == endy&& here.dir == enddir) {
			return here.count;
		}

		if (GO != here.preCommand) {
			int nextx = here.x + DIR[here.dir - 1][0];
			int nexty = here.y + DIR[here.dir - 1][1];
			while (0 == map[nexty][nextx] && 0 == visited[nexty][nextx]) {
				Node nextNode(nextx, nexty, here.dir, here.count + 1, GO);
				qq.push(nextNode);
				visited[nextNode.y][nextNode.x] = 1;
				nextx += DIR[here.dir - 1][0];
				nexty += DIR[here.dir - 1][1];
			}

		}
		if (TURN != here.preCommand) {
			for (int i = 0; i < 2; ++i) {
				int nextdir = turn(here.dir, i);
				Node nextNode(here.x, here.y, nextdir, here.count + 1, TURN);
				qq.push(nextNode);
			}
			int nextdir = turn(here.dir, 2);
			Node nextNode(here.x, here.y, nextdir, here.count + 2, TURN);
			qq.push(nextNode);
		}
	}

	return 0;
}

int main()
{
	cin >> height >> width;
	map.assign(height + 2, vector<int>(width + 2, 1));
	for (int i = 1; i < map.size() - 1; ++i) {
		for (int j = 1; j < map[i].size() - 1; ++j) {
			cin >> map[i][j];
		}
	}
	cin >> starty >> startx >> startdir;
	cin >> endy >> endx >> enddir;

	cout << bfs() << endl;

	return 0;
}