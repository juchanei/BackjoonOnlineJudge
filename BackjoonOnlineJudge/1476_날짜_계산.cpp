#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	if (15 == a) a = 0;
	if (28 == b) b = 0;
	if (19 == c) c = 0;

	int x = 1;
	while (1) {
		if (a == x % 15 && b == x % 28 && c == x % 19) {
			break;
		}
		x++;
	}

	cout << x << endl;

	return 0;
}
