#include <iostream>
#include <vector>
using namespace std;

int nn = 0;

int power(int a, int b)
{
	int ret = 1;
	for (int i = 0; i < b; i++)
		ret *= a;
	return ret;
}

vector<vector<int> > map;

int cnt = 0;
void recu(int hereLen, int hereX, int hereY)
{
	if (1 == hereLen){
		++cnt;
		return;
	}

	int nextLen = hereLen / 2;
	int nextX = hereX + nextLen;
	int nextY = hereY + nextLen;

	recu(nextLen, hereX, hereY);
	recu(nextLen, nextX, hereY);
	recu(nextLen, hereX, nextY);
	recu(nextLen, nextX, nextY);
}

int main()
{
	nn = 15;
	recu(power(2, nn), 0, 0);
	cout << cnt << endl;

	return 0;
}