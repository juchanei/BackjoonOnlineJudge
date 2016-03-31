#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
	int value;
	int count;
	Node(int value, int count) : value(value), count(count) {}
	Node() : value(0), count(0) {}
};

int nNode;
vector<vector<int> > adjList;
vector<int> visited;
vector<int> delegates;

int getMaxDepth(int start, int visitedId, int minDepth)
{
	vector<int> visitedNode(nNode + 1, 0);
	queue<Node> qq;
	Node startNode(start, 0);
	qq.push(startNode);
	visitedNode[start] = 1;
	visited[start] = visitedId;

	Node here;
	while (!qq.empty()) {
		here = qq.front();
		qq.pop();
		
		if (minDepth == here.count) {
			return 987654321;
		}

		for (int i = 0; i < adjList[here.value].size(); ++i) {
			int nextValue = adjList[here.value][i];
			if (0 == visitedNode[nextValue]) {
				Node next(nextValue, here.count + 1);
				qq.push(next);
				visitedNode[nextValue] = 1;
				visited[nextValue] = visitedId;
			}
		}
	}
	return here.count;
}

void bfsAll()
{
	visited.assign(nNode + 1, 0);

	int count = 0;
	int visitedId = 1;
	for (int i = 1; i < visited.size(); ++i) {
		if (0 == visited[i]) {
			int minDepth = getMaxDepth(i, visitedId, 987654321);;
			int minNode = i;

			for (int j = 1; j < visited.size(); ++j) {
				if (visitedId == visited[j] && j != i) {
					int ret = getMaxDepth(j, visitedId, minDepth);
					if (ret < minDepth) {
						minDepth = ret;
						minNode = j;
					}
				}
			}

			delegates.push_back(minNode);
		}
		visitedId++;
	}
}

int main()
{
	int nEdge;
	cin >> nNode >> nEdge;

	adjList.assign(nNode + 1, vector<int>(0));

	for (int i = 0; i < nEdge; ++i) {
		int nodeA, nodeB;
		scanf("%d %d\n", &nodeA, &nodeB);
		adjList[nodeA].push_back(nodeB);
		adjList[nodeB].push_back(nodeA);
	}

	bfsAll();

	sort(delegates.begin(), delegates.end());
	cout << delegates.size() << endl;
	for (int i = 0; i < delegates.size(); ++i) {
		cout << delegates[i] << endl;
	}

	return 0;
}