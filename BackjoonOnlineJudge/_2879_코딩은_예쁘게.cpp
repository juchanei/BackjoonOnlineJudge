#include <iostream>
using namespace std;

int tabMap[1001][3] = { 0, };

bool isPositive(int a)
{
	if (0 < a)
		return true;
	else
		return false;
}

int main()
{
	int nLine = 0;
	cin >> nLine;
	for (int i = 0; i < nLine; ++i){
		int currentTap = 0;
		cin >> currentTap;
		tabMap[i][0] = currentTap;
	}
	for (int i = 0; i < nLine; ++i){
		int targetTap = 0;
		cin >> targetTap;
		tabMap[i][1] = targetTap;
		tabMap[i][2] = tabMap[i][1] - tabMap[i][0];
	}


	bool prePositive = isPositive(tabMap[0][2]);

	int localMax = 0;
	int localMin = 0;
	int count = 0;
	for (int i = 0; i < nLine; ++i){
		bool currentPositive = isPositive(tabMap[i][2]);

		if (prePositive != currentPositive){
			count -= localMin;
			count += localMax;
			localMax = 0;
			localMin = 0;
		}

		if (currentPositive == false){
			if (tabMap[i][2] < localMin){
				localMin = tabMap[i][2];
			}
		}
		else{
			if (localMax < tabMap[i][2]){
				localMax = tabMap[i][2];
			}
		}

		prePositive = currentPositive;
	}
	count -= localMin;
	count += localMax;

	cout << count << endl;

	return 0;
}