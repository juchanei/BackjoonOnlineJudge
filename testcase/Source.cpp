#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int tc = 1;
	cout << tc << endl;
	while (tc--) {
		int h = 3000;
		cout << h << endl;
		for (size_t i = 0; i < h; i++) {
			printf("%d %d %d\n", rand() % 5001, rand() % 5001, rand() % 3001);
		}
	}

	return 0;
}