#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int h = 1000;
	cout << h << endl;
	for (size_t i = 0; i < h; i++)
	{
		printf("%d %d\n", rand() % h + 1, rand() % h + 1);
	}

	return 0;
}