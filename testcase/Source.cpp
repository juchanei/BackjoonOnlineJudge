#include <iostream>
using namespace std;

int main()
{
	cout << 10000 << " " << 100000 << endl;

	int i;
	for (i = 1; i < 10000; ++i){
		printf("%d %d\n", i, i + 1);
	}
	for (i; i <= 100000; ++i){
		int a = rand() % 300 + 1;
		int b = rand() % (400 - a + 1);
		printf("%d %d\n", a, a + b);
	}

	return 0;
}