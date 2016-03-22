#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct Node{
	int next;
	int cost;
	Node(int next, int cost) :next(next), cost(cost) {}
	Node() :next(0), cost(0) {}
};

struct Result{
	int value;
	int count;
	int path;
	Result() : value(0), count(0), path(0) {}
};

vector<vector<Node> > adjList;
vector<int> benefit;
vector<Result> cache;

Result dfs(int here)
{
	if (0 != cache[here].count){
		return cache[here];
	}

	Result maxReturn;
	for (int i = 0; i < adjList[here].size(); i++){
		Result temp = dfs(adjList[here][i].next);
		if (maxReturn.value <= temp.value - adjList[here][i].cost){
			maxReturn.value = temp.value - adjList[here][i].cost;
			maxReturn.count = temp.count;
			maxReturn.path = adjList[here][i].next;
		}
	}

	maxReturn.value += benefit[here];
	maxReturn.count += 1;

	cache[here] = maxReturn;
	return maxReturn;
}

int main()
{
	int tc;
	cin >> tc;

	while (tc--){
		int nNode, nEdge;
		cin >> nNode >> nEdge;

		adjList.assign(nNode + 1, vector<Node>(0, Node()));
		cache.assign(nNode + 1, Result());

		benefit.assign(nNode + 1, 0);
		for (int i = 1; i < benefit.size(); i++)
		{
			scanf("%d ", &benefit[i]);
		}

		for (int i = 0; i < nEdge; i++){
			int nodeA, nodeB, cost;
			scanf("%d %d %d ", &nodeA, &nodeB, &cost);
			adjList[nodeA].push_back(Node(nodeB, cost));
		}

		Result result = dfs(1);
		cout << result.value << " " << result.count << endl;

		int next = 1;
		for (int i = 0; i < result.count; ++i){
			printf("%d ", next);
			next = cache[next].path;
		}
		cout << endl;
	}

	return 0;
}