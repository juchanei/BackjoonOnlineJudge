#include <iostream>
#include <vector>
using namespace std;

int triangleSize;
vector<vector<int> > triangle;
vector<vector<int> > cache;

int max(int a, int b)
{
	return a < b ? b : a;
}

int recu(int xx, int yy)
{
	if (triangleSize <= yy) {
		return 0;
	}
	int& ret = cache[xx][yy];
	if (-1 != ret) {
		return ret;
	}
		
	int maxValue = 0;
	maxValue = max(maxValue, recu(xx, yy + 1) + triangle[yy][xx]);
	maxValue = max(maxValue, recu(xx + 1, yy + 1) + triangle[yy][xx]);

	ret = maxValue;
	return maxValue;
}

int main()
{
	cin >> triangleSize;
	triangle.assign(triangleSize, vector<int>(triangleSize, -1));
	
	for (int i = 0; i < triangle.size(); ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> triangle[i][j];
		}
	}

	cache.assign(triangleSize, vector<int>(triangleSize, -1));
	cout << recu(0, 0) << endl;

	return 0;
}