#include <iostream>
using namespace std;

int adjArr[1001][1001] = { 0, };

int minSum = 0;
void dfs(int nHouse, int here, int color, int sum)
{
	if (sum > minSum){
		return;
	}

	if (nHouse == here){
		if (sum < minSum){
			minSum = sum;
		}
		return;
	}

	for (int i = 0; i < 3; ++i){
		if (i != color){
			dfs(nHouse, here + 1, i, sum + adjArr[here][i]);
		}
	}
}

int main()
{
	int nHouse = 0;
	cin >> nHouse;

	minSum = nHouse * 1000;

	for (int i = 0; i < nHouse; ++i){
		for (int j = 0; j < 3; ++j){
			cin >> adjArr[i][j];
		}
	}

	for (int i = 0; i < 3; ++i){
		dfs(nHouse, 1, i, adjArr[0][i]);
	}

	cout << minSum << endl;

	return 0;
}