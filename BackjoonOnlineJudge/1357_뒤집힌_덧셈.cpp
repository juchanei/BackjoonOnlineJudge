#include <iostream>
using namespace std;

int rev(int num)
{
	int out = 0;
	while (0 < num) {
		out = out * 10 + num % 10;
		num /= 10;
	}
	return out;
}

int main()
{
	int x, y;
	cin >> x >> y;
	cout << rev(rev(x) + rev(y)) << endl;

	return 0;
}