#include <iostream>
using namespace std;
int main()
{
	int nn = 1000;
	cout << nn << " " << nn << endl;
	for (size_t i = 0; i < nn; i++)
	{
		for (size_t j = 0; j < nn; j++)
		{
			printf("1 ");
		}
		printf("\n");
	}

	return 0;
}