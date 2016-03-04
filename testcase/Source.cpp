#include <iostream>
using namespace std;

int main()
{
	int size = 100;
	cout << size << endl;

	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; j++)
		{
			printf("%d ", rand() % 2);
		}
		printf("\n");
	}

	return 0;
}