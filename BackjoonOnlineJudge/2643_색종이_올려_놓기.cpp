#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;

const int INF = 987654321;
vector<pair<int, int> > papers;
vector<vector<int> > cache;

int max(int a, int b)
{
	return a < b ? b : a;
}

int dfs(const int paperIndex, const int prePaperIndex)
{
	if (paperIndex == papers.size()) {
		return 0;
	}

	int& ret = cache[paperIndex][prePaperIndex];
	if (-1 != ret) {
		return ret;
	}

	int maxValue = 0;
	if (papers[paperIndex].first <= papers[prePaperIndex].first &&
		papers[paperIndex].second <= papers[prePaperIndex].second) {
		maxValue = max(maxValue, dfs(paperIndex + 1, paperIndex) + 1);	//selected
	}
	maxValue = max(maxValue, dfs(paperIndex + 1, prePaperIndex));		//not selected

	ret = maxValue;
	return ret;
}

int main()
{
	int nPaper;
	cin >> nPaper;

	cache.assign(nPaper + 1, vector<int>(nPaper + 1, -1));

	papers.assign(nPaper + 1, pair<int, int>());
	papers[0].first = INF;
	papers[0].second = INF;
	for (int i = 1; i < papers.size(); ++i) {
		int aa, bb;
		cin >> aa >> bb;

		if (aa < bb) {
			int temp = aa;
			aa = bb;
			bb = temp;
		}

		papers[i].first = aa;
		papers[i].second = bb;
	}
	sort(papers.begin(), papers.end(), greater<pair<int, int> >());

	cout << dfs(1, 0) << endl;

	return 0;
}