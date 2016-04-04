#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;

vector<int> questions;
vector<vector<vector<int> > > cache;

int min(int a, int b)
{
	return a < b ? a : b;
}

int dfs(int questionIndex, int doorA, int doorB)
{
	if (questionIndex == questions.size()) {
		return 0;
	}

	int& ret = cache[questionIndex][doorA][doorB];
	if (-1 != ret) {
		return ret;
	}

	if (doorB < doorA) {
		int temp = doorA;
		doorA = doorB;
		doorB = temp;
	}

	int target = questions[questionIndex];

	int minValue = INF;
	if (target <= doorA) {
		minValue = min(minValue, dfs(questionIndex + 1, target, doorB) + doorA - target);
	}
	else if (doorA < target && target < doorB) {
		minValue = min(minValue, dfs(questionIndex + 1, target, doorB) + target - doorA);
		minValue = min(minValue, dfs(questionIndex + 1, doorA, target) + doorB - target);
	}
	else if (doorB <= target) {
		minValue = min(minValue, dfs(questionIndex + 1, doorA, target) + target - doorB);
	}
	
	ret = minValue;
	return ret;
}

int main()
{
	int nBox, doorA, doorB, nQuestion;
	cin >> nBox >> doorA >> doorB >> nQuestion;
	questions.assign(nQuestion, 0);
	for (int i = 0; i < nQuestion; ++i) {
		cin >> questions[i];
	}

	cache.assign(nQuestion, vector<vector<int> >(nBox + 1, vector<int>(nBox + 1, -1)));
	cout << dfs(0, doorA, doorB) << endl;

	return 0;
}