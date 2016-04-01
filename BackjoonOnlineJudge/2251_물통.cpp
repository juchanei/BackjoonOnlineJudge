#include <iostream>
#include <vector>
using namespace std;

int aa, bb, cc;
vector<vector<vector<int> > > visited;
vector<int> result;

void foo(int arr[3], int from, int to)
{

}

void recu(int aa, int bb, int cc)
{
	visited[aa][bb][cc] = 1;
	if (1 == result[cc]) {
		return;
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i != j) {
				if (0 == visited[aa][bb][cc]) {
					int arr[3] = { 0, };
					arr[0] = aa;
					arr[1] = bb;
					arr[2] = cc;
					foo(arr, i, j);
					recu(arr[0], arr[1], arr[2]);
				}
			}
		}
	}
}

int main()
{
	cin >> aa >> bb >> cc;
	visited.assign(aa + 1, vector<vector<int> >(bb + 1, vector<int>(cc + 1, -1)));
	result.assign(cc + 1, 0);

	recu(aa, bb, cc);

	for (int i = 1; i < result.size(); ++i) {
		if (1 == result[i]) {
			cout << i << " ";
		}
	}
	cout << endl;

	return 0;
}