#include <iostream>
using namespace std;

int stringState[6][300001] = { 0, };
int cnt = 0;

void foo(int string, int fret)
{
	int& nFinger = stringState[string][0];
	if (0 == nFinger){
		++nFinger;
		stringState[string][nFinger] = fret;
		++cnt;
		return;
	}

	while (fret < stringState[string][nFinger]){
		stringState[string][nFinger] = 0;
		--nFinger;
		++cnt;
	}

	if (stringState[string][nFinger] < fret){
		++nFinger;
		stringState[string][nFinger] = fret;
		++cnt;
		return;
	}
}

int main()
{
	int nNote = 0;
	int nFret = 0;
	cin >> nNote >> nFret;

	for (int i = 0; i < nNote; i++)
	{
		int string = 0;
		int fret = 0;
		cin >> string >> fret;
		--string;

		foo(string, fret);
	}

	cout << cnt << endl;

	return 0;
}