#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > adjList;
vector<int> salaries;

void dfs(int start, int here, int change)
{
	for (int i = 0; i < adjList[here].size(); ++i){
		int next = adjList[here][i];
		salaries[next] += change;
		dfs(start, next, change);
	}
}

int main()
{
	int nEmployee, nQuerry;
	cin >> nEmployee >> nQuerry;

	adjList = vector<vector<int> >(nEmployee + 1, vector<int>(0));
	salaries = vector<int>(nEmployee + 1, 0);

	cin >> salaries[1];
	for (int i = 2; i <= nEmployee; ++i){
		int boss;
		scanf("%d %d\n", &salaries[i], &boss);
		adjList[boss].push_back(i);
	}

	for (int i = 0; i < nQuerry; ++i){
		char command;
		scanf("%c ", &command);

		if (command == 'p'){
			int employee, change;
			scanf("%d %d\n", &employee, &change);
			dfs(employee, employee, change);
		}
		else if (command == 'u'){
			int employee;
			scanf("%d\n", &employee);
			printf("%d\n", salaries[employee]);
		}
	}

	return 0;
}