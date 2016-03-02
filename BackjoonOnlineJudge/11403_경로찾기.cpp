#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int> >& adjArr, vector<int>& visitedNode, const int here)
{
	visitedNode.at(here) = 1;
	for (int i = 0; i < adjArr.at(here).size(); ++i){
		if (1 == adjArr.at(here).at(i) && 0 == visitedNode.at(i)){
			dfs(adjArr, visitedNode, i);
		}
	}

}

void printVector(const vector<int>& visitedNode)
{
	for (int i = 0; i < visitedNode.size(); ++i){
		cout << visitedNode.at(i) << " ";
	}
	cout << endl;
}

int main()
{
	int nNode = 0;
	cin >> nNode;

	vector<vector<int> > adjArr(nNode, vector<int>(nNode, 0));

	for (int i = 0; i < adjArr.size(); ++i){
		for (int j = 0; j < adjArr.at(i).size(); ++j){
			cin >> adjArr.at(i).at(j);
		}
	}

	for (int i = 0; i < adjArr.size(); ++i){
		vector<int> visitedNode(nNode, 0);
		dfs(adjArr, visitedNode, i);
		printVector(visitedNode);
	}

	return 0;
}