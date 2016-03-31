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
<DFS + ����/���� DP>
	Ư�� ��带 �����ϴ��� �����ĸ� �����ϴ� ����
	�Ϲ����� ����/���� ������ Ž���� ���������� �ϴ� �Ͱ� �޸�
	�� ������ Ž���� Ʈ�������� �ؾ��ϴ� ���� �ֿ� �̽�

	�Ϲ� dfs�� ���� �ϵ�, ���� ���� �Ѿ�� ������ ����/���� �ΰ�����
	��Ʈ��尡 ������ ��� �����ִ� �׷����� �ص� �ȴ�
	������ ��Ʈ��尡 �˷����� �ʴ°�쿡�� ������� �׷����� visited �迭�� �̿��Ѵ�
	visited üũ�� Ž���� �θ�� �������� �ʴ� ���Ҹ� �ϹǷ� ���������� ����?�Ѵ�
	���� ĳ���� �̿��� DP�� �����ϴ�
*/