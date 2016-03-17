#include <iostream>
//#include <queue>
using namespace std;

int map[102][102] = { 0, };

const int DIR[4][2] = {
	0, -1,
	0, 1,
	-1, 0,
	1, 0
};

struct Node{
	int xx;
	int yy;
	int count;
	Node(int xx, int yy, int count) :xx(xx), yy(yy), count(count) {}
	Node() :xx(0), yy(0), count(0) {}
};

Node queuearr[10000];
struct queue{
	int head;
	int rear;
	Node front()
	{
		head++;
		return queuearr[head - 1];
	}
	void pop() {}
	void push(Node data)
	{
		queuearr[rear] = data;
		rear++;
	}
	bool empty()
	{
		if (rear == head) return true;
		return false;
	}
	queue() :head(0), rear(0) {}
};


int bfs(int endX, int endY)
{
	Node startNode(1, 1, 1);
	queue qq;
	qq.push(startNode);
	map[1][1] = 3;

	while (!qq.empty()){
		Node here = qq.front();
		qq.pop();

		if (here.xx == endX && here.yy == endY){
			return here.count;
		}

		for (int i = 0; i < 4; ++i){
			int nextX = here.xx + DIR[i][1];
			int nextY = here.yy + DIR[i][0];

			if (1 == map[nextY][nextX]){
				Node next(nextX, nextY, here.count + 1);
				qq.push(next);
				map[next.yy][next.xx] = 3;
			}
		}
	}
	return -1;
}

int main()
{
	int height, width;
	cin >> height >> width;

	for (int i = 1; i <= height; ++i){
		for (int j = 1; j <= width; ++j){
			char temp;
			cin >> temp;
			map[i][j] = temp - '0';
		}
	}

	cout << bfs(width, height) << endl;

	return 0;
}