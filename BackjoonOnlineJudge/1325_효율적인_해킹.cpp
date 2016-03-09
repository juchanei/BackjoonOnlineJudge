#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adjList;
vector<int> visited;

int dfs(int start, int here)
{
	visited[here] = start;

	int sum = 1;
	for (int i = 0; i < adjList.at(here).size(); ++i){
		int next = adjList.at(here).at(i);
		if (start != visited.at(next)){
			sum += dfs(start, next);
		}
	}

	return sum;
}

int main()
{
	int nNode = 0;
	int nEdge = 0;
	cin >> nNode >> nEdge;

	adjList = vector<vector<int> >(nNode + 1, vector<int>(0));
	visited = vector<int>(nNode + 1, 0);

	for (int i = 0; i < nEdge; ++i){
		int nodeA = 0;
		int nodeB = 0;
		cin >> nodeA >> nodeB;
		adjList.at(nodeB).push_back(nodeA);
	}

	vector<int> results;
	int maxReturnValue = 0;
	for (int i = 1; i < adjList.size(); ++i){
		int returnValue = dfs(i, i);

		if (maxReturnValue < returnValue){
			maxReturnValue = returnValue;
			results.clear();
			results.push_back(i);
		}
		else if (maxReturnValue == returnValue){
			results.push_back(i);
		}
	}

	cout << results.at(0) << " ";
	for (int i = 1; i < results.size(); ++i){
		cout << results.at(i) << " ";
	}
	cout << endl;

	return 0;
}