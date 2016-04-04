#include <iostream>
#include <vector>
using namespace std;

vector<int> bottle(3, 0);
vector<vector<vector<int> > > visited;
vector<int> result;

void pour(vector<int>& currentBottle, int from, int to)
{
	int toRemain = bottle[to] - currentBottle[to];
	if (currentBottle[from] <= toRemain) {
		currentBottle[to] += currentBottle[from];
		currentBottle[from] = 0;
	}
	else if (toRemain < currentBottle[from]) {
		currentBottle[to] = bottle[to];
		currentBottle[from] -= toRemain;
	}
	return;
}

void recu(vector<int> bottle)
{
	visited[bottle[0]][bottle[1]][bottle[2]] = 1;
	if (0 == bottle[0]) {
		result[bottle[2]] = 1;
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i != j) {
				vector<int> nextBottle(bottle);
				pour(nextBottle, i, j);
				if (0 == visited[nextBottle[0]][nextBottle[1]][nextBottle[2]]) {
					recu(nextBottle);
				}
			}
		}
	}
}

int main()
{
	cin >> bottle[0] >> bottle[1] >> bottle[2];
	visited.assign(bottle[0] + 1, vector<vector<int> >(bottle[1] + 1, vector<int>(bottle[2] + 1, 0)));
	result.assign(bottle[2] + 1, 0);

	vector<int> nextBottle(3, 0);
	nextBottle[2] = bottle[2];
	recu(nextBottle);

	for (int i = 0; i < result.size(); ++i) {
		if (1 == result[i]) {
			cout << i << " ";
		}
	}
	cout << endl;

	return 0;
}