#include <iostream>
using namespace std;

void dfs(int targetSum, int remainSum, int& count)
{
	if (0 == remainSum){
		++count;
		return;
	}

	if (0 > remainSum){
		return;
	}

	for (int i = 1; i <= 3; ++i){
		dfs(targetSum, remainSum - i, count);
	}
}

int main()
{
	int tc = 0;
	cin >> tc;

	while (tc--){
		int targetSum = 0;
		cin >> targetSum;

		int count = 0;
		dfs(targetSum, targetSum, count);

		cout << count << endl;
	}
	return 0;
}