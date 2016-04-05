#include <iostream>
#include <vector>
using namespace std;

const int DIR[4][2] = {
	0, 0,
	0, 1,
	1, 0,
	1, 1
};

const int NO = 987654321;

vector<vector<char> > map;

int countX(int x, int y)
{
	int nX = 0;

	for (int i = 0; i < 4; ++i) {
		char temp = map[y + DIR[i][1]][x + DIR[i][0]];
		if ('#' == temp) {
			return NO;
		}
		else if ('X' == temp) {
			nX++;
		}
	}

	return nX;
}

int main()
{
	int height, width;
	cin >> height >> width;
	map.assign(height + 2, vector<char>(width + 2, '#'));
	for (int i = 1; i < map.size() - 1; ++i) {
		for (int j = 1; j < map[0].size() - 1; ++j) {
			cin >> map[i][j];
		}
	}

	vector<int> rets(4 + 1, 0);
	for (int i = 1; i < map.size() - 2; ++i) {
		for (int j = 1; j < map[0].size() - 2; ++j) {
			int ret = countX(j, i);
			if (NO == ret) continue;
			rets[ret] += 1;
		}
	}

	for (int i = 0; i <= 4; ++i) {
		cout << rets[i] << endl;
	}

	return 0;
}