#include <iostream>
using namespace std;

int main()
{
	cout << 1 << endl;
	cout << 100000 << endl;

	for (int i = 0; i < 100000 - 1; ++i) {
		printf("%d ", i + 2);//rand() % 100000);
	}

	cout << 1 << " ";

	return 0;
}