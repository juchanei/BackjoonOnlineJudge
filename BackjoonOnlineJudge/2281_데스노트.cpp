#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int width;
vector<int> names;

int min(int a, int b)
{
	return a < b ? a : b;
}

int dfs(int here, int nameIndex)
{
	if (names.size() == nameIndex) {
		return 0;
	}

	int minValue = 987654321;
	if (names[nameIndex] < width - names[nameIndex])
		minValue = min(minValue, dfs(here + 1 + names[nameIndex], nameIndex + 1));
	minValue = min(minValue, dfs(0, nameIndex + 1) + (width - here) * (width - here));

	return minValue;
}


int main()
{
	int nName;
	cin >> nName >> width;

	names.assign(nName, 0);
	for (int i = 0; i < nName; ++i) {
		cin >> names[i];
	}

	cout << dfs(0, 0) << endl;

	return 0;
}