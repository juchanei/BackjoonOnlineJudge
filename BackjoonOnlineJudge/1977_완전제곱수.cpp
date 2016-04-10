#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int start, end;
	cin >> start >> end;

	vector<int> squared(102, 0);
	for (int i = 1; i < squared.size(); ++i) {
		squared[i] = i * i;
	}

	int j = 0;
	for (; squared[j] < start; ++j);
	int min = squared[j];
	int sum = 0;
	for (; squared[j] <= end; ++j) {
		sum += squared[j];
	}

	if (0 == sum) {
		cout << -1 << endl;
		return 0;
	}

	cout << sum << endl << min << endl;

	return 0;
}