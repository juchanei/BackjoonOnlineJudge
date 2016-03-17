#include <iostream>
using namespace std;

int nn, yy, xx;

int power(int a, int b)
{
	int ret = 1;
	for (int i = 0; i < b; i++)
		ret *= a;
	return ret;
}

int result;
void recu(int hereLen, int hereX, int hereY)
{
	if (1 == hereLen) return;

	int nextLen = hereLen / 2;
	int nextX = hereX + nextLen;
	int nextY = hereY + nextLen;
	int addSize = power(nextLen, 2);

	if (xx < nextX && yy < nextY){
		recu(nextLen, hereX, hereY);
	}
	else if (nextX <= xx && yy < nextY){
		result += addSize;
		recu(nextLen, nextX, hereY);
	}
	else if (xx < nextX && nextY <= yy){
		result += addSize * 2;
		recu(nextLen, hereX, nextY);
	}
	else if (nextX <= xx && nextY <= yy){
		result += addSize * 3;
		recu(nextLen, nextX, nextY);
	}
}

int main()
{
	while (cin >> nn >> yy >> xx){
		result = 0;
		recu(power(2, nn), 0, 0);
		cout << result << endl;
	}
	return 0;
}