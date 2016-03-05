#include <iostream>
#include <stdio.h>
//#include <stack>
using namespace std;

void dfs(int* adjList, int* visitedNode, int& nNode, int& start, int here, int count, int&result, bool& found)
{
	visitedNode[here] = 1;
	if (start == here) {
		result += count;
		found = true;
		return;
	}

	if (0 == visitedNode[adjList[here]]) {
		dfs(adjList, visitedNode, nNode, start, adjList[here], count + 1, result, found);
		if (true == found) return;
	}

	visitedNode[here] = 0;
}

//struct Node
//{
//	int value;
//	int count;
//	Node(int value, int count) :value(value), count(count) {}
//	Node() {}
//};

int main()
{
	int tc = 0;
	cin >> tc;

	while (tc--) {
		int nNode = 0;
		cin >> nNode;
		
		int adjList[100001] = { 0, };
		int visitedNode[100001] = { 0, };

		for (int i = 1; i <= nNode; ++i) {
			int temp = 0;
			scanf("%d", &temp);
			adjList[i] = temp;
		}

		int result = 0;
		for (int i = 1; i <= nNode; ++i) {
			if (0 == visitedNode[adjList[i]]) {
				bool found = false;
				dfs(adjList, visitedNode, nNode, i, adjList[i], 1, result, found);

				//stack<Node> ss;
				//Node startNode(adjList[i], 1);
				//ss.push(startNode);
				//
				//while (!ss.empty()) {
				//	Node here = ss.top();
				//	ss.pop();
				//	visitedNode[here.value] = 1;

				//	if (here.value == i) {
				//		result += here.count;
				//		break;
				//	}

				//	if (0 == visitedNode[adjList[here.value]]) {
				//		Node next(adjList[here.value], here.count + 1);
				//		ss.push(next);
				//	}
				//}
				//
				//
			}
		}

		cout << nNode - result << endl;
	}

	return 0;
}