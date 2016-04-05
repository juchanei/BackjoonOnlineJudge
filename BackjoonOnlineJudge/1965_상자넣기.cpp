#include <iostream>
#include <vector>
using namespace std;

vector<int> boxes;
vector<vector<int> > cache;

int max(int a, int b)
{
	return a < b ? b : a;
}

int lis(int boxIndex, int preBoxIndex)
{
	if (boxIndex == boxes.size()) {
		return 0;
	}

	int& ret = cache[boxIndex][preBoxIndex];
	if (-1 != ret) {
		return ret;
	}

	int maxValue = 0;
	if (boxes[preBoxIndex] < boxes[boxIndex]) {
		maxValue = max(maxValue, lis(boxIndex + 1, boxIndex) + 1);
	}
	maxValue = max(maxValue, lis(boxIndex + 1, preBoxIndex));

	ret = maxValue;
	return maxValue;
}

int main()
{
	int nBox;
	cin >> nBox;

	cache.assign(nBox + 1, vector<int>(nBox + 1, -1));
	boxes.assign(nBox + 1, 0);
	boxes[0] = 0;
	for (int i = 1; i < boxes.size(); ++i) {
		cin >> boxes[i];
	}

	cout << lis(1, 0) << endl;

	return 0;
}