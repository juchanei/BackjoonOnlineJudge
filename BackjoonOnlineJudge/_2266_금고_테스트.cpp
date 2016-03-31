#include <iostream>
using namespace std;

int main()
{
	int nFloor, nBox;
	cin >> nFloor >> nBox;

	int count = 0;
	int half = nFloor;
	while (1 < nBox && 1 < half) {
		half /= 2;
		nBox--;
		count++;
	}
	count += half;

	cout << count << endl;
	return 0;
}