#include <iostream>
using namespace std;

int selection[100001] = { 0, };
int visited[100001] = { 0, };

void dfs(int start, int here, bool& found)
{
	if (here == start){
		found = true;
		selection[here] = -1;
		return;
	}
	if (-2 == selection[here]){
		return;
	}
	visited[here] = start;

	if (start != visited[selection[here]]){
		dfs(start, selection[here], found);
	}

	if (true == found){
		selection[here] = -1;
	}
}

int main()
{
	int tc = 0;
	cin >> tc;
	while (tc--){
		int nNode = 0;
		cin >> nNode;
		for (int i = 1; i <= nNode; ++i){
			cin >> selection[i];
		}
;
		for (int i = 1; i <= nNode; ++i){
			if (-1 != selection[i]){
				bool found = false;
				dfs(i, selection[i], found);
				if (false == found){
					selection[i] = -2;
				}
			}
		}

		int count = 0;
		for (int i = 1; i <= nNode; ++i){
			if (-1 != selection[i]){
				++count;
			}
		}
		cout << count << endl;
	}

	return 0;
}