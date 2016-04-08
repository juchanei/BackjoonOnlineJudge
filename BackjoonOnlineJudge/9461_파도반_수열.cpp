#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int nNumber;
	cin >> nNumber;

	vector<unsigned long long> triangles(100 + 1, 0);
	triangles[1] = 1;
	triangles[2] = 1;
	triangles[3] = 1;
	triangles[4] = 2;
	for (int i = 5; i < triangles.size(); ++i) {
		triangles[i] = triangles[i - 1] + triangles[i - 5];
	}

	for (int i = 0; i < nNumber; ++i) {
		int index;
		cin >> index;
		cout << triangles[index] << endl;
	}

	return 0;
}