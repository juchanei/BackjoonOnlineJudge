#include <iostream>
#include <vector>
using namespace std;
#include <queue>

struct Node{
	int value;
	int count;
	Node(int value, int count) :value(value), count(count) {}
};

int calcKB(const vector<int>& visitedNode)
{
	int sum = 0;
	for (int i = 0; i < visitedNode.size(); ++i){
		sum += visitedNode.at(i);
	}

	return sum;
}

void bfs(const vector<vector<int> >& adjList, vector<int>& visitedNode, int start)
{
	Node startNode(start, 0);
	queue<Node> qq;
	qq.push(startNode);
	visitedNode.at(start) = startNode.count;

	while (!qq.empty()){
		Node here = qq.front();
		qq.pop();

		for (int i = 0; i < adjList.at(here.value).size(); ++i){
			const int nextValue = adjList.at(here.value).at(i);
			if (-1 == visitedNode.at(nextValue)){
				const Node next(adjList.at(here.value).at(i), here.count + 1);
				qq.push(next);
				visitedNode.at(nextValue) = next.count;
			}
		}
	}
}


int main()
{
	int nNode = 0;
	int nEdge = 0;
	cin >> nNode >> nEdge;

	vector<vector<int> > adjList(nNode + 1, vector<int>(0,0));

	for (int i = 0; i < nEdge; ++i){
		int nodeA = 0;
		int nodeB = 0;
		cin >> nodeA >> nodeB;
		adjList.at(nodeA).push_back(nodeB);
		adjList.at(nodeB).push_back(nodeA);
	}

	vector<pair<int, int> > kbValues(0, pair<int, int>(0,0));
	for (int i = 1; i < adjList.size(); ++i){
		vector<int> visitedNode(nNode + 1, -1);
		bfs(adjList, visitedNode, i);
		kbValues.push_back(pair<int, int>(i, calcKB(visitedNode)));
	}

	pair<int, int> smallKBperson(0, 9999);
	for (int i = 0; i < kbValues.size(); ++i){
		if (kbValues.at(i).second < smallKBperson.second){
			smallKBperson = kbValues.at(i);
		}
	}

	cout << smallKBperson.first << endl;

	return 0;
}