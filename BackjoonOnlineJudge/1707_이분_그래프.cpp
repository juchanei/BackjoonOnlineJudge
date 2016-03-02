#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<vector<int> >& adjList, vector<int>& visitedNode, const int here, const int preGroup, bool& found)
{
	if (1 == preGroup){
		visitedNode.at(here) = 2;
	}
	else if (2 == preGroup){
		visitedNode.at(here) = 1;
	}

	for (int i = 0; i < adjList.at(here).size(); ++i){
		const int next = adjList.at(here).at(i);
		if (0 == visitedNode.at(next)){
			dfs(adjList, visitedNode, next, visitedNode.at(here), found);
			if (true == found){
				return;
			}
		}
		else{
			if (visitedNode.at(next) == visitedNode.at(here)){
				found = true;
				return;
			}
		}
	}
}

int main()
{
	int testcase = 0;
	cin >> testcase;

	while (testcase--){
		int nNode = 0;
		int nEdge = 0;
		cin >> nNode >> nEdge;

		vector<vector<int> > adjList(nNode + 1, vector<int>(0));
		vector<int> visitedNode(nNode + 1, 0);

		for (int i = 0; i < nEdge; ++i){
			int nodeA = 0;
			int nodeB = 0;
			cin >> nodeA >> nodeB;

			adjList.at(nodeA).push_back(nodeB);
			adjList.at(nodeB).push_back(nodeA);
		}

		bool found = false;
		for (int i = 1; i < adjList.size(); ++i){
			if (0 == visitedNode.at(i)){
				int start = i;
				visitedNode.at(start) = 1;
				dfs(adjList, visitedNode, start, visitedNode.at(start), found);
			}
		}
		if (true == found){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
		}
	}

	return 0;
}