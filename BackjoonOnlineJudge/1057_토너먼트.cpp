#include <iostream>
using namespace std;

int main()
{
	int nPlayer, playerA, playerB;
	cin >> nPlayer >> playerA >> playerB;

	int count = 0;
	while (playerA != playerB){
		playerA = (playerA + 1) / 2;
		playerB = (playerB + 1) / 2;
		count++;
	}

	cout << count << endl;

	return 0;
}