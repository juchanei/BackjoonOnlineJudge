#include <iostream>
#include <stdio.h>
using namespace std;

int adjArr[401][401] = { 0, };
int visited[401] = { 0, };
int orders[401] = { 0, };
int branches[401] = { 0, };
int nNode = 0;

void init()
{
	for (int i = 0; i < 401; ++i){
		for (int j = 0; j < 401; ++j)
		{
			adjArr[i][j] = 0;
		}
		visited[i] = 0;
		orders[i] = 0;
		branches[i] = 0;
	}
	nNode = 0;
}

void dfs(int start, int here, int& count, int& branch)
{
	visited[here] = start;

	for (int i = 1; i <= nNode; ++i){
		if (1 == adjArr[here][i] && 0 == visited[i]){
			dfs(start, i, count, branch);
		}
		else if (1 == adjArr[here][i] && start != visited[i] && 0 != visited[i]){
			count = orders[i] - 1;
			branch = orders[i];
		}
	}
	++count;
	orders[here] = count;
	branches[here] = branch;
}

int main()
{
	int nEdge = 0;
	cin >> nNode >> nEdge;

	for (int i = 0; i < nEdge; ++i){
		int nodeA = 0;
		int nodeB = 0;
		cin >> nodeA >> nodeB;
		adjArr[nodeA][nodeB] = 1;
	}

	int count = 0;
	int branch = 1;
	for (int i = 1; i <= nNode; ++i){
		int outEdge = 0;
		int inEdge = 0;

		for (int j = 1; j <= nNode; ++j){
			if (1 == adjArr[i][j]) ++outEdge;
			if (1 == adjArr[j][i]) ++inEdge;
		}

		if (0 < outEdge && 0 == inEdge){
			dfs(i, i, count, branch);
		}
	}

	int nQuestion = 0;
	cin >> nQuestion;

	for (int i = 0; i < nQuestion; ++i){
		int eventA = 0;
		int eventB = 0;
		cin >> eventA >> eventB;

		if (branches[eventA] == branches[eventB]){
			if (orders[eventA] < orders[eventB]){
				printf("-1\n");
			}
			else if (orders[eventA] < orders[eventB]){
				printf("1\n");
			}
			else{
				printf("0\n");
			}
		}
		else{
			if (branches[eventA] > orders[eventB]){
				printf("1\n");
			}
			else{
				printf("0\n");
			}
		}
	}

	init();
	return 0;
}