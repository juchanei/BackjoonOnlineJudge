#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int h = 10000;
	cout << h << endl;
	for (size_t i = 0; i + 2 <= h; i++)
	{
		printf("%d %d %d\n", i + 1, i + 2, 1);
	}

	return 0;
}