#include <iostream>
#include <vector>
using namespace std;

int height, width;
vector<vector<char> > map;
vector<vector<int> > visited;

void throwAndBreak(int heightFromBottom, bool fromRight)
{
	int hh = height - heightFromBottom + 1;
	if (fromRight) {
		int iter = width;
		while ('.' == map[hh][iter]) --iter;
		if ('x' == map[hh][iter]) {
			map[hh][iter] = '.';
		}
	}
	else {
		int iter = 1;
		while ('.' == map[hh][iter]) ++iter;
		if ('x' == map[hh][iter]) {
			map[hh][iter] = '.';
		}
	}
}

const int DIR[4][2] = { 0, -1, 0, 1, -1, 0, 1, 0 };
void grouping(int xx, int yy, int value)
{
	visited[yy][xx] = value;

	for (int i = 0; i < 4; ++i) {
		if ('x' == map[yy + DIR[i][1]][xx + DIR[i][0]]
			&& 0 == visited[yy + DIR[i][1]][xx + DIR[i][0]]) {
			grouping(xx + DIR[i][0], yy + DIR[i][1], value);
		}
	}
}

bool isMineralInAir()
{
	visited.assign(height + 2, vector<int>(width + 2, 0));

	int earth = height;
	int value = 1;
	for (int i = 1; i <= width; ++i) {
		if ('x' == map[earth][i] && 0 == visited[earth][i]) {
			grouping(i, earth, value);
		}
	}

	for (int i = 1; i < height; ++i) {
		for (int j = 1; j <= width; j++) {
			if ('x' == map[i][j] && 0 == visited[i][j]) {
				++value;
				grouping(j, i, value);
			}
		}
	}

	if (1 < value) {
		return true;
	}
	return false;
}

struct Position
{
	int x;
	int y;
	Position(int x, int y) :x(x), y(y) {}
};

bool isInAir(const vector<Position>& under)
{
	for (int i = 0; i < under.size(); ++i) {
		if ('x' == map[under[i].y + 1][under[i].x]
			|| 0 == map[under[i].y + 1][under[i].x]) {
			return false;
		}
	}
	return true;
}

void downMess(vector<Position>& under)
{
	for (int i = height - 1; i > 0; --i) {
		for (int j = width; j > 0; --j) {
			if (1 < visited[i][j]) {
				visited[i + 1][j] = 2;
				visited[i][j] = 0;
				map[i + 1][j] = 'x';
				map[i][j] = '.';
			}
		}
	}
	for (int i = 0; i < under.size(); ++i) {
		under[i].y += 1;
	}
}

void fallDownMineral()
{
	vector<Position> under;
	for (int i = 1; i < height; ++i) {
		for (int j = 1; j <= width; j++) {
			if (1 < visited[i][j] && '.' == map[i + 1][j]) {
				under.push_back(Position(j, i));
			}
		}
	}

	while (1) {
		if (isInAir(under)) {
			downMess(under);
			continue;
		}
		break;
	}
}

void printMap()
{
	for (int i = 1; i <= height; ++i) {
		for (int j = 1; j <= width; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

int main()
{
	cin >> height >> width;

	map.assign(height + 2, vector<char>(width + 2, 0));

	for (int i = 1; i <= height; ++i) {
		for (int j = 1; j <= width; j++) {
			cin >> map[i][j];
		}
	}

	int nThrow;
	cin >> nThrow;
	for (int i = 0; i < nThrow; ++i) {
		int throwHeight;
		cin >> throwHeight;

		throwAndBreak(throwHeight, i % 2);

		if (isMineralInAir()) {
			fallDownMineral();
		}
	}

	printMap();
	return 0;
}