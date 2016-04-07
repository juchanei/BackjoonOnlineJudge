#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > arr;
vector<vector<int> > sum;

int main()
{
	int height, width;
	cin >> height >> width;
	arr.assign(height + 1, vector<int>(width + 1, 0));
	for (int i = 1; i < arr.size(); ++i) {
		for (int j = 1; j < arr[i].size(); ++j) {
			cin >> arr[i][j];
		}
	}

	sum.assign(height + 1, vector<int>(width + 1, 0));
	for (int i = 1; i < arr.size(); ++i) {
		for (int j = 1; j < arr[i].size(); ++j) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
		}
	}

	int nQuestion;
	cin >> nQuestion; 
	for (int i = 0; i < nQuestion; ++i) {
		int startx, starty, endx, endy;
		cin >> starty >> startx >> endy >> endx;

		cout << sum[endy][endx] - sum[starty - 1][endx] - sum[endy][startx - 1] + sum[starty - 1][startx - 1] << endl;;
	}

	return 0;
}
