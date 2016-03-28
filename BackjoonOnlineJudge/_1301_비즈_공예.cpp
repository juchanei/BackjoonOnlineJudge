#include <iostream>
#include <vector>
using namespace std;

vector<int> nBeed;
vector<int> neckless;

int dfs(int here, int color)
{
	nBeed[color] -= 1;
	neckless[here] = color;

	if (here == neckless.size() - 1){
		nBeed[color] += 1;
		neckless[here] = 0;
		return 1;
	}

	int sum = 0;
	for (int i = 1; i < nBeed.size(); ++i){
		if (0 < nBeed[i] && i != neckless[here] && i != neckless[here - 1]){
			sum +=dfs(here + 1, i);
		}
	}

	nBeed[color] += 1;
	return sum;
}

int main()
{
	int nBeedType;
	cin >> nBeedType;

	nBeed.assign(nBeedType + 1, 0);
	int sum = 0;
	for (int i = 1; i < nBeed.size(); ++i){
		cin >> nBeed[i];
		sum += nBeed[i];
	}

	int cnt = 0;
	neckless.assign(sum + 2, 0);
	for (int i = 1; i < nBeed.size(); ++i){
		cnt += dfs(2, i);
	}

	cout << cnt << endl;

	return 0;
}