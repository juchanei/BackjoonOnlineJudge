#include <iostream>
using namespace std;

int main()
{
	cout << 400 << " " << 50000 << endl;

	for (int i = 0; i < 50000; ++i){
		printf("%d %d\n", rand() % 400 + 1, rand() % 400 + 1);
	}

	cout << 50000 << endl;
	for (int i = 0; i < 50000; ++i){
		printf("%d %d\n", rand() % 400 + 1, rand() % 400 + 1);
	}

	return 0;
}