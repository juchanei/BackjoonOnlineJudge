#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
	int to;
	int weight;
	Edge(int to, int weight) :to(to), weight(weight) {}
	Edge() :to(0), weight(0) {}
};

vector<vector<Edge> > adjList;
vector<int> visited;

int maxDiameter;
int dfs(int here, int weight)
{
	visited[here] = 1;

	vector<int> diameters;
	for (int i = 0; i < adjList[here].size(); ++i) {
		int next = adjList[here][i].to;
		if (0 == visited[next]) {
			int nextWeight = adjList[here][i].weight;
			int ret = dfs(next, nextWeight);
			diameters.push_back(ret);
		}
	}
	int currentDiameter = 0;
	sort(diameters.begin(), diameters.end());
	int size = diameters.size();
	if (0 == size) {
		return weight;
	}
	else if (1 == size) {
		currentDiameter = diameters[size - 1];
	}
	else if (2 <= size) {
		currentDiameter = diameters[size - 1] + diameters[size - 2];
	}
	if (maxDiameter < currentDiameter) {
		maxDiameter = currentDiameter;
	}
	return diameters[size - 1] + weight;
}

int main()
{
	int nNode;
	cin >> nNode;
	adjList.assign(nNode + 1, vector<Edge>(0));
	visited.assign(nNode + 1, 0);
	maxDiameter = 0;

	int nodeA, nodeB, weight;
	while (cin >> nodeA >> nodeB >> weight) {
		adjList[nodeA].push_back(Edge(nodeB, weight));
		adjList[nodeB].push_back(Edge(nodeA, weight));
	}

	dfs(1, 0);
	cout << maxDiameter << endl;

	return 0;
}