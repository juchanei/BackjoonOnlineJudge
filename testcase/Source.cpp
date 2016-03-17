#include <iostream>
using namespace std;

int main()
{
	int n = 500000;
	int q = 50000;
	cout << n << " " << q << endl;

	cout << rand() % 100000 + 1 << endl;
	for (int i = 1; i < n; ++i){
		printf("%d ", rand() % n + 1);
		printf("%d\n", rand() % 100000 + 1);
	}

	for (int i = 1; i < q; ++i){
		int temp = rand() % 2;

		if (temp == 0){
			printf("p %d %d\n", rand() % n + 1, rand() % 20000 - 10000);
		}
		else if (temp == 1){
			printf("u %d\n", rand() % n + 1);
		}
	}

	return 0;
}