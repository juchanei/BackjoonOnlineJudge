#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ull;

vector<ull> koongs;

int main()
{
	koongs.assign(69, 0);
	koongs[0] = 1;
	koongs[1] = 1;
	koongs[2] = 2;
	koongs[3] = 4;
	ull sum = 8;

	for (int i = 4; i < koongs.size(); ++i) {
		koongs[i] = sum;
		sum -= koongs[i - 4];
		sum += koongs[i];
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int index;
		cin >> index;
		cout << koongs[index] << endl;
	}

	return 0;
}