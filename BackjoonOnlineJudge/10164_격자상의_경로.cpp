#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > cache;

int recu(int xx, int yy, int destx, int desty)
{
	if (xx == destx && yy == desty) {
		return 1;
	}
	else if (destx < xx || desty < yy) {
		return 0;
	}
	int& ret = cache[yy][xx];
	if (-1 != ret) {
		return ret;
	}

	int sum = 0;
	sum += recu(xx + 1, yy, destx, desty);
	sum += recu(xx, yy + 1, destx, desty);

	ret = sum;
	return sum;
}

int main()
{
	int height, width, circle;
	cin >> height >> width >> circle;

	if (0 == circle) {
		cache.assign(height + 1, vector<int>(width + 1, -1));
		cout << recu(1, 1, width, height) << endl;
		return 0;
	}

	int height1 = (circle - 1) / width + 1;
	int width1 = (circle - 1) % width + 1;

	int height2 = height - height1 + 1;
	int width2 = width - width1 + 1;

	cache.assign(height1 + 1, vector<int>(width1 + 1, -1));
	int ret1 = recu(1, 1, width1, height1);
	cache.assign(height2 + 1, vector<int>(width2 + 1, -1));
	int ret2 = recu(1, 1, width2, height2);
	cout << ret1 * ret2 << endl;

	return 0;
}