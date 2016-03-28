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

		//부시지 않고 진입
		for (int i = 0; i < 4; ++i){
			if (0 == map[here.yy + DIR[i][1]][here.xx + DIR[i][0]]){
				if (true == here.breakWall){
					//부실 수 있는 상태일 때 visited가 1만 아니면 모두 진입
					if (1 != visited[here.yy + DIR[i][1]][here.xx + DIR[i][0]]){
						Node next(here.xx + DIR[i][0], here.yy + DIR[i][1], here.count + 1, here.breakWall);
						qq.push(next);
						visited[next.yy][next.xx] = 1;
					}
				}
				else{
					//부실 수 없는 상태일 때 visited가 0인 경우에만 진입
					if (0 == visited[here.yy + DIR[i][1]][here.xx + DIR[i][0]]){
						Node next(here.xx + DIR[i][0], here.yy + DIR[i][1], here.count + 1, here.breakWall);
						qq.push(next);
						visited[next.yy][next.xx] = 2;
					}
				}
			}
		}

		//부시고 진입
		for (int i = 0; i < 4; ++i){
			//진입할 곳이 벽이고 부실 수 있는 상태에만 진입
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