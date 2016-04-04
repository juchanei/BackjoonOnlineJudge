#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 987654321;

struct Node
{
	int val;
	int count;
	Node(int val, int count) : val(val), count(count) {}
	Node() : val(0), count(0) {}
};

int nNode;
vector<vector<int> > adjList;

int bfs(int start)
{
	vector<int> visited(nNode + 1, 0);
	queue<Node> qq;
	Node startNode(start, 0);
	qq.push(startNode);
	visited[startNode.val] = 1;

	Node here;
	while (!qq.empty()) {
		here = qq.front();
		qq.pop();

		for (int i = 0; i < adjList[here.val].size(); ++i) {
			int next = adjList[here.val][i];
			if (0 == visited[next]) {
				Node nextNode(next, here.count + 1);
				qq.push(nextNode);
				visited[nextNode.val] = 1;
			}
		}
	}

	return here.count;
}

int main()
{
	cin >> nNode;

	adjList.assign(nNode + 1, vector<int>(0));

	int nodeA, nodeB;
	while (1) {
		cin >> nodeA >> nodeB;
		if (-1 == nodeA && -1 == nodeB) {
			break;
		}
		adjList[nodeA].push_back(nodeB);
		adjList[nodeB].push_back(nodeA);
	}

	vector<int> delegates(0);
	int minValue = INF;
	for (int i = 1; i < adjList.size(); ++i) {
		int ret = bfs(i);
		if (ret < minValue) {
			minValue = ret;
			delegates.clear();
			delegates.push_back(i);
		}
		else if (ret == minValue) {
			delegates.push_back(i);
		}
	}

	sort(delegates.begin(), delegates.end());
	cout << minValue << " " << delegates.size() << endl;
	for (int i = 0; i < delegates.size(); ++i) {
		cout << delegates[i] << " ";
	}
	cout << endl;

	return 0;
}