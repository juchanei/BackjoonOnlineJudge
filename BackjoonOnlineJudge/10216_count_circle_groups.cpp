#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct Position
{
	int x;
	int y;
	int r;
	Position(int x, int y, int r) : x(x), y(y), r(r) {}
	Position() : x(0), y(0), r(0) {}
};

vector<Position> nodes;
vector<vector<int> > adjList;
vector<int> visited;

bool isConnected(int nodeIndexA, int nodeIndexB)
{
	int xDiff = nodes[nodeIndexA].x - nodes[nodeIndexB].x;
	int yDiff = nodes[nodeIndexA].y - nodes[nodeIndexB].y;
	int squaredDistance = xDiff * xDiff + yDiff * yDiff;
	int sumRadious = nodes[nodeIndexA].r + nodes[nodeIndexB].r;
	int squaredSumRadious = sumRadious * sumRadious;

	return squaredDistance <= squaredSumRadious ? true : false;
}

void dfs(int here)
{
	visited[here] = 1;

	for (int i = 0; i < adjList[here].size(); ++i) {
		int next = adjList[here][i];
		if (0 == visited[next]) {
			dfs(next);
		}
	}
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--) {
		int nNode;
		cin >> nNode;

		nodes.clear();
		adjList.assign(nNode, vector<int>(0));
		visited.assign(nNode, 0);

		for (int i = 0; i < nNode; ++i) {
			int xx, yy, rr;
			scanf("%d %d %d\n", &xx, &yy, &rr);
			nodes.push_back(Position(xx, yy, rr));
		}

		for (int i = 0; i < nodes.size() - 1; ++i) {
			for (int j = i + 1; j < nodes.size(); ++j) {
				if (isConnected(i, j)) {
					adjList[i].push_back(j);
					adjList[j].push_back(i);
				}
			}
		}

		int count = 0;
		for (int i = 0; i < nodes.size(); ++i) {
			if (0 == visited[i]) {
				dfs(i);
				count++;
			}
		}

		cout << count << endl;
	}

	return 0;
}