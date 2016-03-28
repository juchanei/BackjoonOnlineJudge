#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int h = 1000;
	int w = 1000;
	cout << h << " " << w << endl;
	for (size_t i = 0; i < h; i++)
	{
		for (size_t j = 0; j < w; j++)
		{
			cout << 0;
		}
		cout << endl;
	}

	return 0;
}