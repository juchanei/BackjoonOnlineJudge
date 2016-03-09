#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

vector<vector<int> > adjList;
vector<int> visited;

void dfs(int dest, int here, bool& found)
{
	visited.at(here) = 1;
	if (here == dest){
		found = true;
		return;
	}

	for (int i = 0; i < adjList.at(here).size(); ++i){
		int next = adjList.at(here).at(i);
		if (0 == visited.at(next)){
			dfs(dest, next, found);
			if (true == found) return;
		}
	}
}

int main()
{
	int nNode = 0;
	int nEdge = 0;
	cin >> nNode >> nEdge;

	adjList = vector<vector<int> >(nNode + 1, vector<int>(0));

	for (int i = 0; i < nEdge; ++i){
		int nodeA = 0;
		int nodeB = 0;
		scanf("%d %d", &nodeA, &nodeB);

		adjList.at(nodeA).push_back(nodeB);
	}

	int nQuestion = 0;
	cin >> nQuestion;

	for (int i = 0; i < nQuestion; ++i){
		visited = vector<int>(nNode + 1, 0);
		int event1 = 0;
		int event2 = 0;
		scanf("%d %d", &event1, &event2);

		bool found = false;
		dfs(event2, event1, found);
		if (true == found){
			printf("-1\n");
			continue;
		}

		visited = vector<int>(nNode + 1, 0);
		found = false;
		dfs(event1, event2, found);
		if (true == found){
			printf("1\n");
			continue;
		}
		printf("0\n");
	}
}