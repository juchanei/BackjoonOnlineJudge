#include <iostream>
using namespace std;

const int midpoint = 15;
const int DirValue[4][2] = {
	1, 0,
	-1, 0,
	0, 1,
	0, -1
};

double DirWeight[4] = { 0, };
bool visited[31][31] = { 0, };

int nMove = 0;
double totalProbability = 0;

void dfs(int xx, int yy, double probability, int count)
{
	visited[yy][xx] = true;

	if (count == nMove){
		totalProbability += probability;
		visited[yy][xx] = false;
		return;
	}

	for (int i = 0; i < 4; ++i){
		if (0 == visited[yy + DirValue[i][1]][xx + DirValue[i][0]]){
			dfs(xx + DirValue[i][0], yy + DirValue[i][1], probability * DirWeight[i], count + 1);
		}
	}

	visited[yy][xx] = false;
}

int main()
{
	cin >> nMove;

	for (int i = 0; i < 4; ++i){
		cin >> DirWeight[i];
		DirWeight[i] /= 100;
	}
	
	dfs(midpoint, midpoint, 1, 0);

	cout << totalProbability << endl;

	return 0;
}