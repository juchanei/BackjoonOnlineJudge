#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
vector<vector<int> > adjList;
vector<vector<int> > cache;
vector<int> visited;

int min(int a, int b)
{
	return a < b ? a : b;
}

int getNumberofNodes(int here)
{
	visited[here] = 1;

	int sum = 0;
	for (int i = 0; i < adjList[here].size(); ++i) {
		int next = adjList[here][i];
		if (0 == visited[next]) {
			sum += getNumberofNodes(next) + 1;
		}
	}
	return sum;
}

int dfs(int here, bool isSelected)
{
	visited[here] = 1;
	int& ret = cache[here][isSelected];
	if (-1 != ret) {
		return ret;
	}

	bool isLeaf = true;
	int sum = 0;
 	for (int i = 0; i < adjList[here].size(); ++i) {
		int next = adjList[here][i];
		if (0 == visited[next]) {
			int minValue = INF;
			if (true == isSelected) {
				minValue = min(minValue, dfs(next, false));
			}
			minValue = min(minValue, dfs(next, true) + 1);
			sum += minValue;
		}
	}

	ret = sum;
	visited[here] = 0;
	return ret;
}

int main()
{
	int nNode;
	cin >> nNode;

	adjList.assign(nNode + 1, vector<int>(0));
	cache.assign(nNode + 1, vector<int>(2, -1));
	visited.assign(nNode + 1, 0);

	for (int i = 0; i < nNode - 1; ++i) {
		int nodeA, nodeB;
		cin >> nodeA >> nodeB;
		adjList[nodeA].push_back(nodeB);
		adjList[nodeB].push_back(nodeA);
	}

	int minValue = INF;
	minValue = min(minValue, dfs(1, false));
	minValue = min(minValue, dfs(1, true) + 1);

	cout << minValue << endl;

	return 0;
}

/*
<DFS + 선택/비선택 DP>
	특정 노드를 선택하느냐 마느냐를 선택하는 문제
	일반적인 선택/비선택 문제가 탐색을 선형구조로 하는 것과 달리
	이 문제는 탐색을 트리구조로 해야하는 것이 주요 이슈

	일반 dfs와 같이 하되, 다음 노드로 넘어가는 방향이 선택/비선택 두가지다
	루트노드가 고정되 경우 방향있는 그래프로 해도 된다
	하지만 루트노드가 알려지지 않는경우에는 방향없는 그래프와 visited 배열을 이용한다
	visited 체크는 탐색이 부모로 역행하지 않는 역할만 하므로 참조투명성을 보장?한다
	따라서 캐싱을 이용한 DP가 가능하다
*/