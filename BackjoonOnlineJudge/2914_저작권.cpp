#include <iostream>
using namespace std;

int main()
{
	int nSong, average;
	cin >> nSong >> average;

	cout << (average - 1) * nSong + 1 << endl;

	return 0;
}