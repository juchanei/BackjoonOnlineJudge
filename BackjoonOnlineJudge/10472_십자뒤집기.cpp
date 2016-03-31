#include <iostream>
#include <vector>
using namespace std;

vector<vector<char> > targetBoard;

int min(int a, int b)
{
	return a < b ? a : b;
}

void change(vector<vector<char> >& board, int xx, int yy)
{
	const int DIR[5][2] = {
		0, 0,
		0, -1,
		0, 1,
		-1, 0,
		1, 0
	};

	for (int i = 0; i < 5; ++i) {
	char& point = board[yy + DIR[i][1]][xx + DIR[i][0]];
		if ('*' == point) {
			point = '.';
		}
		else if ('.' == point) {
			point = '*';
		}
	}
}

int recu(vector<vector<char> > here, int position, int count)
{
	if (here == targetBoard) {
		return 0;
	}

	if (9 < count) {
		return 987654321;
	}

	int minValue = 987654321;
	minValue = min(minValue, recu(here, position + 1, count + 1));
	
	int row = position / 3 + 1;
	int col = position % 3 + 1;
	change(here, col, row);
	minValue = min(minValue, recu(here, position + 1, count + 1) + 1);

	return minValue;
}

void initBoard(vector<vector<char> >& board)
{
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			board[i][j] = '.';
		}
	}
}

int main()
{
	int tc;
	cin >> tc;

	while (tc--) {
		targetBoard.assign(5, vector<char>(5, '_'));
		for (int i = 1; i <= 3; ++i) {
			for (int j = 1; j <= 3; ++j) {
				cin >> targetBoard[i][j];
			}
		}

		vector<vector<char> > board(5, vector<char>(5, '_'));
		initBoard(board);
		cout << recu(board, 0, 1) << endl;
	}

	return 0;
}