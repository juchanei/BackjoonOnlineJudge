#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

vector<int> sum;
vector<vector<int> > table;

int main()
{
	int length, height;
	cin >> length >> height;

	sum.assign(height + 1, 0);
	table.assign(height + 1, vector<int>(2, 0));
	for (int i = 1; i < length / 2 + 1; ++i) {
		int aa, bb;
		scanf("%d %d\n", &aa, &bb);
		table[aa][0]++;
		table[bb][1]++;
	}

	for (int i = 1; i < table.size(); ++i) {
		sum[1] += table[i][0];
	}
	sum[1] += table[table.size() - 1][1];

	for (int i = 2; i < sum.size(); ++i) {
		sum[i] = sum[i - 1] - table[i - 1][0] + table[table.size() - i][1];
	}

	sort(sum.begin(), sum.end());
	int minBreak = sum[1];
	for (int i = 2; i < sum.size(); ++i) {
		if (minBreak != sum[i]) {
			cout << minBreak << endl;
			cout << i - 1 << endl;
			break;
		}
	}

	return 0;
}