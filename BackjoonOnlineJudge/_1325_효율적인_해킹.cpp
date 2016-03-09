#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int> > adjList;
vector<int> visited;
//vector<pair<int, int> > nInOutEdges;

int dfs(int group, int start)
{
	stack<int> ss;
	ss.push(start);
	visited.at(start) = group;

	int count = 0;
	while (!ss.empty()){
		int here = ss.top();
		ss.pop();

		visited.at(here) = start;
		++count;

		int returnValue = 1;
		for (int i = 0; i < adjList.at(here).size(); ++i){
			int next = adjList.at(here).at(i);
			if (start != visited.at(next)){
				ss.push(next);
			}
		}
	}

	return count;
}

void sort(vector<pair<int, int> >& result)
{
	for (int i = 0; i < result.size() - 1; ++i){
		for (int j = i + 1; j < result.size(); ++j){
			if (result.at(i).second < result.at(j).second){
				pair<int, int> temp = result.at(i);
				result.at(i) = result.at(j);
				result.at(j) = temp;
			}
		}
	}
}

int main()
{
	int nNode = 0;
	int nEdge = 0;
	cin >> nNode >> nEdge;

	adjList = vector<vector<int> >(nNode + 1, vector<int>(0));
	//nInOutEdges = vector<pair<int, int> >(nNode + 1, pair<int, int>(0, 0));

	for (int i = 0; i < nEdge; ++i){
		int nodeA = 0;
		int nodeB = 0;
		cin >> nodeA >> nodeB;
		adjList.at(nodeB).push_back(nodeA);
		//nInOutEdges.at(nodeA).second += 1;
		//nInOutEdges.at(nodeB).first += 1;
	}

	int returValue = 0;
	vector<pair<int, int> > result;
	visited = vector<int>(nNode + 1, 0);
	for (int i = 1; i < adjList.size(); ++i){
		if (0 == visited.at(i)){
			//if (0 < nInOutEdges.at(i).first && 0 == nInOutEdges.at(i).second){
				result.push_back(pair<int, int>(i, dfs(i, i)));
			//}
		}
	}

	sort(result);

	cout << result.at(0).first << " ";
	for (int i = 1; i < result.size(); ++i){
		if (result.at(0).second == result.at(i).second){
			cout << result.at(i).first << " ";
		}
	}
	cout << endl;

	return 0;
}