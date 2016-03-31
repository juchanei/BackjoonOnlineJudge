#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int nNode;
const int INF = 987654321;
vector<vector<int> > adjList;
vector<int> visited;
vector<vector<int> > cache;

int min(int a, int b)
{
	return a < b ? a : b;
}

int recu(int here, int currentColor)
{
	int& ret = cache[here][currentColor];
	if (-1 != ret) {
		return ret;
	}
	visited[here] = 1;

	int sum = 0;
	for (int i = 0; i < adjList[here].size(); ++i) {
		int minValue = INF;
		int next = adjList[here][i];
		if (0 == visited[next]) {
			for (int j = 1; j <= 4; ++j) {
				if (currentColor != j) {
					minValue = min(minValue, recu(next, j) + j);
				}
			}
		}
		if (INF != minValue) {
			sum += minValue;
		}
	}

	visited[here] = 0;
	ret = sum;
	return ret;
}

int main()
{
	cin >> nNode;

	adjList.assign(nNode + 1, vector<int>(0));
	visited.assign(nNode + 1, 0);
	cache.assign(nNode + 1, vector<int>(4 + 1, -1));

	for (int i = 0; i < nNode - 1; ++i) {
		int nodeA, nodeB;
		scanf("%d %d\n", &nodeA, &nodeB);
		adjList[nodeA].push_back(nodeB);
		adjList[nodeB].push_back(nodeA);
	}

	int minValue = INF;
	for (int i = 1; i <= 4; ++i) {
		minValue = min(minValue, recu(1, i) + i);
	}

	cout << minValue << endl;

	return 0;
}

/*
	2533_사회망_서비스와 매우 유사한 문제
	4색정리를 알아야 메모리 초과가 안난다.
*/