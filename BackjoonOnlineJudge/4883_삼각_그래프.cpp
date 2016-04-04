#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int INF = 987654321;

vector<vector<int> > input;
vector<vector<vector<pair<int, int> > > > adjList;
vector<vector<int> > visited;
vector<vector<int> > cache;


int nLine;

void makeGraph()
{
	for (int i = 0; i < input.size(); ++i) {
		for (int j = 0; j < input[0].size(); ++j) {
			//4°³
			if (i + 1 < input.size() && 0 <= j - 1) {
				adjList[i][j].push_back(pair<int, int>(i + 1, j - 1));
			}
			if (i + 1 < input.size()) {
				adjList[i][j].push_back(pair<int, int>(i + 1, j));
			}
			if (i + 1 < input.size() && j + 1 < input[0].size()) {
				adjList[i][j].push_back(pair<int, int>(i + 1, j + 1));
			}
			if (j + 1 < input[0].size()) {
				adjList[i][j].push_back(pair<int, int>(i, j + 1));
			}
		}
	}

}

int min(int a, int b)
{
	return a < b ? a : b;
}

int dfs(int xx, int yy)
{
	int& ret = cache[yy][xx];
	if (-1 != ret) {
		return ret;
	}
	if (xx == 1 && yy == nLine - 1) {
		return input[yy][xx];
	}

	int minValue = INF;
	for (int i = 0; i < adjList[yy][xx].size(); ++i) {
		int nexty = adjList[yy][xx][i].first;
		int nextx = adjList[yy][xx][i].second;
		if (0 == visited[nexty][nextx]) {
			minValue = min(minValue, dfs(nextx, nexty) + input[yy][xx]);
		}
	}

	ret = minValue;
	return ret;
}

int main()
{
	int cnt = 1;
	while (1) {
		cin >> nLine;
		if (0 == nLine) {
			break;
		}

		input.assign(nLine, vector<int>(3, 0));
		visited.assign(nLine, vector<int>(3, 0));
		cache.assign(nLine, vector<int>(3, -1));
		for (int i = 0; i < nLine; ++i) {
			scanf("%d %d %d\n", &input[i][0], &input[i][1], &input[i][2]);
		}

		adjList.assign(nLine, vector<vector<pair<int, int> > >(3, vector<pair<int, int> >(0)));
		makeGraph();

		cout << cnt << ". ";
		cout << dfs(1, 0) << endl;
		cnt++;
	}

	return 0;
}