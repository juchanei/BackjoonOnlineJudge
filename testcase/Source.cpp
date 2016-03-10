#include <iostream>
using namespace std;

int main()
{
	cout << 100000 << endl;
	for (int i = 0; i < 100000; ++i){
		printf("%d\n", rand() % 20001 - 10000);
	}

	return 0;
}