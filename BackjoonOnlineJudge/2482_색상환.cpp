#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000003;

int nPickColor;
vector<int> visited;
vector<vector<int> > cache;

int cnt = 0;
int dfs(int here, int count)
{
	if (0 != cache[here][count]) {
		return cache[here][count];
	}
	cnt++;
	if (count == nPickColor) {
		cache[here][count] = 1;
		return 1;
	}
	visited[here] = 1;

	int sum = 0;
	for (int i = here + 2; i < visited.size(); ++i) {
		if (0 == visited[i]) {
			sum += dfs(i, count + 1);
		}
	}
	sum %= MOD;

	cache[here][count] = sum;
	visited[here] = 0;
	return sum;
}

int main()
{
	int nColor;
	cin >> nColor >> nPickColor;
	visited.assign(nColor, 0);
	cache.assign(nColor, vector<int>(nPickColor + 1, 0));

	int sum = 0;
	visited[0] = 1;
	visited[visited.size() - 1] = 1;
	sum += dfs(0, 1);
	visited[0] = 0;
	visited[visited.size() - 1] = 0;

	int startColorLimit = (nColor - 1) - (nPickColor - 1) * 2;
	for (int i = 1; i <= startColorLimit; ++i) {
		visited[i] = 1;
		sum += dfs(i, 1);
		visited[i] = 0;
	}

	cout << sum % MOD << endl;
	cout << cnt << endl;

	return 0;
}