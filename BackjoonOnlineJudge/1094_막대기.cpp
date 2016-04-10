#include <iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;

	int length = 64;
	int count = 0;
	while (0 < length) {
		if (x < length) {
			length /= 2;
		}
		else {
			x -= length;
			count++;
		}
	}

	cout << count << endl;

	return 0;
}