#include <iostream>
using namespace std;

int table[10][4];

int main()
{
	int tc;
	cin >> tc;

	for (int j = 0; j < 4; j++)
	{
		table[0][j] = 10;
	}
	for (int i = 1; i < 10; i++)
	{
		table[i][1] = i;
		for (int j = 2; j < 4; j++)
		{
			table[i][j] = (table[i][j - 1] * i) % 10;
		}
		table[i][0] = (table[i][3] * i) % 10;
	}

	while (tc--){
		int aa, bb;
		cin >> aa >> bb;

		aa %= 10;
		int index = bb % 4;
		cout << table[aa][index] << endl;
	}
	return 0;
}