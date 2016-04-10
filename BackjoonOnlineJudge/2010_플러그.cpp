#include <iostream>
using namespace std;

int main()
{
	int nMultitap;
	cin >> nMultitap;

	int sum = 0;
	for (int i = 0; i < nMultitap; ++i) {
		int currentMultitap;
		cin >> currentMultitap;
		sum += currentMultitap;
	}
	cout << sum - (nMultitap - 1) << endl;

	return 0;
}