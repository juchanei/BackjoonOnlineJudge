#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int xx;
	int yy;
	int count;
	bool breakWall;
	Node(int xx, int yy, int count, bool breakWall) :xx(xx), yy(yy), count(count), breakWall(breakWall) {}
	Node() :xx(0), yy(0), count(0), breakWall(true) {}
};

const int DIR[4][2] = {
	0, -1,
	0, 1,
	-1, 0,
	1, 0
};

vector<vector<int> > map, visited;

int bfs()
{
	queue<Node> qq;
	Node startNode(1, 1, 1, true);
	qq.push(startNode);
	visited[startNode.yy][startNode.xx] = 1;

	while (!qq.empty()){
		Node here = qq.front();
		qq.pop();

		if (here.xx == map[0].size() - 2 && here.yy == map.size() - 2){
			return here.count;
		}

		//�ν��� �ʰ� ����
		for (int i = 0; i < 4; ++i){
			if (0 == map[here.yy + DIR[i][1]][here.xx + DIR[i][0]]){
				if (true == here.breakWall){
					//�ν� �� �ִ� ������ �� visited�� 1�� �ƴϸ� ��� ����
					if (1 != visited[here.yy + DIR[i][1]][here.xx + DIR[i][0]]){
						Node next(here.xx + DIR[i][0], here.yy + DIR[i][1], here.count + 1, here.breakWall);
						qq.push(next);
						visited[next.yy][next.xx] = 1;
					}
				}
				else{
					//�ν� �� ���� ������ �� visited�� 0�� ��쿡�� ����
					if (0 == visited[here.yy + DIR[i][1]][here.xx + DIR[i][0]]){
						Node next(here.xx + DIR[i][0], here.yy + DIR[i][1], here.count + 1, here.breakWall);
						qq.push(next);
						visited[next.yy][next.xx] = 2;
					}
				}
			}
		}

		//�νð� ����
		for (int i = 0; i < 4; ++i){
			//������ ���� ���̰� �ν� �� �ִ� ���¿��� ����
			if (1 == map[here.yy + DIR[i][1]][here.xx + DIR[i][0]]){
				if (true == here.breakWall){
					if (0 == visited[here.yy + DIR[i][1]][here.xx + DIR[i][0]]){
						Node next(here.xx + DIR[i][0], here.yy + DIR[i][1], here.count + 1, false);
						qq.push(next);
						visited[next.yy][next.xx] = 2;
					}
				}
			}
		}
	}

	return 0;
}

int main()
{
	int height, width;
	cin >> height >> width;

	map.assign(height + 2, vector<int>(width + 2, -1));
	visited.assign(height + 2, vector<int>(width + 2, 0));
	scanf("\n");
	for (int i = 1; i < map.size() - 1; ++i){
		for (int j = 1; j < map[i].size() - 1; ++j){
			char temp;
			scanf("%c", &temp);
			map[i][j] = temp - '0';
		}
		scanf("\n");
	}

	cout << bfs() << endl;
	return 0;
}