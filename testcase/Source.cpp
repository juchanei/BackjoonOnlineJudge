#include <iostream>
using namespace std;

int main()
{
	int tc = 10;
	cout << tc << endl;

	while (tc--) {
		int n = 20000;
		int e = 100000;
		cout << n << " " << e << endl;
		for (int i = 0; i < n; ++i) {
			printf("%d ", rand() % 10000 + 1);
		}
		cout << endl;

		for (int i = 0; i < e; ++i) {
			int a = rand() % (n / 2) + 1;
			int b = a + rand() % (n / 2);
			printf("%d %d %d\n", a, b, rand() % 10000 + 1);
		}
	}

	return 0;
}