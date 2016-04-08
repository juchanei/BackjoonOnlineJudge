#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a = 100;
	int b = 10000;
	cout << a << " " << b << endl;
	for (size_t i = 0; i < a; i++) {
		printf("%d\n", i + 1);
	}

	return 0;
}