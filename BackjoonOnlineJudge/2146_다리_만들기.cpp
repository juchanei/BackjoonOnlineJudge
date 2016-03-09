#include <iostream>
using namespace std;

const char Dir[4][2] = {
	0, -1,
	0, 1,
	-1, 0,
	1, 0
};

int map[102][102] = { 0, };

void init(int mapSize)
{
	for (int i = 0; i < mapSize + 2; ++i){
		for (int j = 0; j < mapSize + 2; ++j){
			map[i][j] = -1;
		}
	}
	mapSize = 0;
}

struct Node{
	int xx;
	int yy;
	int count;
	Node(int xx, int yy, int count) :xx(xx), yy(yy), count(count) {}
	Node() :xx(0), yy(0), count(count) {}
};

Node qq[10000];

class Queue{
public:
	int front = 0;
	int rear = 0;

	Node pop()
	{
		Node data = qq[front];
		++front;
		return data;
	}

	void push(Node data)
	{
		qq[rear] = data;
		++rear;
	}

	bool empty()
	{
		if (front == rear) return true;
		else return false;
	}

	Queue()
	{
		front = 0;
		rear = 0;
	}
};

int bfs(int startX, int startY)
{
	Queue qq;
	Node startNode(startX, startY, 0);
	qq.push(startNode);

	int visited[102][102] = { 0, };
	visited[startNode.yy][startNode.yy] = 1;

	while (!qq.empty()){
		Node here = qq.pop();

		if (map[startY][startX] != map[here.yy][here.xx]
			&& 0 !=map[here.yy][here.xx]
			&& 1 < here.count){
			return here.count - 1;
		}

		for (int i = 0; i < 4; ++i){
			if (-1 != map[here.yy + Dir[i][1]][here.xx + Dir[i][0]]
				&& 0 == visited[here.yy + Dir[i][1]][here.xx + Dir[i][0]]){
				Node next(here.xx + Dir[i][0], here.yy + Dir[i][1], here.count + 1);
				qq.push(next);
				visited[here.yy + Dir[i][1]][here.xx + Dir[i][0]] = 1;
			}
		}
	}
}

void dfs(int hereX, int hereY, int color)
{
	map[hereY][hereX] = color;

	for (int i = 0; i < 4; ++i){
		if (1 == map[hereY + Dir[i][1]][hereX + Dir[i][0]]){
			dfs(hereX + Dir[i][0], hereY + Dir[i][1], color);
		}
	}
}

int main()
{
	int mapSize = 0;
	cin >> mapSize;

	init(mapSize);

	for (int i = 1; i < mapSize + 1; ++i){
		for (int j = 1; j < mapSize + 1; ++j){
			cin >> map[i][j];
		}
	}

	int color = 2;
	for (int i = 1; i < mapSize + 1; ++i){
		for (int j = 1; j < mapSize + 1; ++j){
			if (1 == map[i][j]){
				dfs(j, i, color);
				++color;
			}
		}
	}

	int smallValue = 10000;
	for (int i = 1; i < mapSize + 1; ++i){
		for (int j = 1; j < mapSize + 1; ++j){
			if (0 != map[i][j]){
				int returnValue = bfs(j, i);

				if (returnValue < smallValue){
					smallValue = returnValue;
				}
			}
		}
	}

	if (10000 == smallValue){
		cout << 0 << endl;
	}
	else{
		cout << smallValue << endl;
	}

	return 0;
}