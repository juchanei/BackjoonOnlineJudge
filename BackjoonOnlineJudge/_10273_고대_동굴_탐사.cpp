#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct Edge
{
	int nextNode;
	int weight;
	Edge(int nextNode, int weight) :nextNode(nextNode), weight(weight) {}
	Edge() :nextNode(0), weight(0) {}
};

vector<vector<Edge> > adjList;
vector<int> benefit, visited, resultPath;

int maxBenefit;
void dfs(int here, int hereBenefit, vector<int>& path, int depth)
{
	visited[here] = 1;
	path[depth] = here;

	if (maxBenefit < hereBenefit) {
		maxBenefit = hereBenefit;
		resultPath = path;
	}

	for (int i = 0; i < adjList[here].size(); ++i) {
		int next = adjList[here][i].nextNode;
		if (0 == visited[next]) {
			dfs(next, hereBenefit + benefit[next] - adjList[here][i].weight, path, depth + 1);
		}
	}

	path[depth] = 0;
	visited[here] = 0;
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--) {
		int nNode, nEdge;
		cin >> nNode >> nEdge;

		benefit.assign(nNode + 1, 0);
		for (int i = 1; i <= nNode; ++i) {
			scanf("%d ", &benefit[i]);
		}

		adjList.assign(nNode + 1, vector<Edge>(0));
		for (int i = 0; i < nEdge; ++i) {
			int nodeA, nodeB, cost;
			scanf("%d %d %d\n", &nodeA, &nodeB, &cost);
			adjList[nodeA].push_back(Edge(nodeB, cost));
		}

		maxBenefit = 0;
		visited.assign(nNode + 1, 0);

		vector<int> path(nNode + 1, 0);
		path[0] = 1;
		dfs(1, benefit[1], path, 1);

		int size = 0;
		while (0 != resultPath[size]) ++size;
		cout << maxBenefit << " " << size << endl;
		
		for (int i = 0; i < size; ++i) {
			printf("%d ", resultPath[i]);
		}
		cout << endl;
	}

	return 0;
}