#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int INF = 987654321;
const int DIR[3] = { -1, 0, 1 };

vector<vector<int> > arr;
vector<vector<int> > cache;

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a < b ? b : a;
}

int findMin(int lineIndex, int col)
{
	if (lineIndex == arr.size()) {
		return 0;
	}
	int& ret = cache[lineIndex][col];
	if (-1 != ret) {
		return ret;
	}

	int minValue = INF;
	for (int i = 0; i < sizeof(DIR); ++i) {
		int next = col + DIR[i];
		if (0 <= next && next < arr.size()) {
			minValue = min(minValue, findMin(lineIndex + 1, next) + arr[lineIndex][next]);
		}
	}

	ret = minValue;
	return minValue;
}

int findMax(int lineIndex, int col)
{
	if (lineIndex == arr.size()) {
		return 0;
	}
	int& ret = cache[lineIndex][col];
	if (-1 != ret) {
		return ret;
	}

	int maxValue = 0;
	for (int i = 0; i < sizeof(DIR); ++i) {
		int next = col + DIR[i];
		if (0 <= next && next < arr.size()) {
			maxValue = max(maxValue, findMax(lineIndex + 1, next) + arr[lineIndex][next]);
		}
	}

	ret = maxValue;
	return maxValue;
}

int main()
{
	int nLine;
	cin >> nLine;
	arr.assign(nLine, vector<int>(3, 0));
	cache.assign(nLine, vector<int>(3, -1));
	for (int i = 0; i < arr.size(); ++i) {
		scanf("%d %d %d\n", &arr[i][0], &arr[i][1], &arr[i][2]);
	}

	int maxValue = 0;
	for (int i = 0; i < arr[0].size(); ++i) {
		maxValue = max(maxValue, findMax(1, i) + arr[0][i]);
	}
	cache.assign(nLine, vector<int>(3, -1));
	int minValue = INF;
	for (int i = 0; i < arr[0].size(); ++i) {
		minValue = min(minValue, findMin(1, i) + arr[0][i]);
	}

	cout << maxValue << " " << minValue << endl;

	return 0;
}