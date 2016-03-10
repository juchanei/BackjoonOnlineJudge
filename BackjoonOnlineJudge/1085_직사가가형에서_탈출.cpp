#include <iostream>
using namespace std;

int min(int a, int b, int c, int d)
{
	int min1 = a < b ? a : b;
	int min2 = c < d ? c : d;
	return min1 < min2 ? min1 : min2;
}

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << min(x, w - x, y, h - y) << endl;
	return 0;
}