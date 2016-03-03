#include <iostream>
#include <vector>
using namespace std;

struct Edge{
	int nextNode;
	int length;
	int isRushHour;
	Edge(int nextNode, int length, int isRushHour)
		:nextNode(nextNode), length(length), isRushHour(isRushHour) {}
	Edge() {};
};

double rushHourStart;
double rushHourEnd;

double getTakeTime(double currentTime, double length)
{ 
	double result = 0;

	return result;
}

void dfs(const vector<vector<Edge> >& adjList, vector<int>& visitedNode, const int here, const int dest, const double currentTime, double& result)
{
	visitedNode.at(here) = 1;

	if (here == dest){
		if (currentTime > result){
			result = currentTime;
		}
		return;
	}

	for (int i = 0; i < adjList.at(here).size(); ++i){
		const int next = adjList.at(here).at(i).nextNode;
		if (0 == visitedNode.at(next)){
			double moveTime = 0;
			if (adjList.at(here).at(i).isRushHour){
				moveTime = getTakeTime(currentTime, adjList.at(here).at(i).length);
			}
			else{
				moveTime = currentTime, adjList.at(here).at(i).length;
			}
			dfs(adjList, visitedNode, next, dest, currentTime + moveTime, result);
		}
	}

	visitedNode.at(here) = 0;
}

int main()
{
	int nNode = 0;
	int nEdge = 0;
	cin >> nNode >> nEdge >> rushHourStart >> rushHourEnd;

	vector<vector<Edge> >adjList(nNode + 1, vector<Edge>(0));

	for (int i = 0; i < nEdge; ++i){
		int nodeA = 0;
		int nodeB = 0;
		int edgeLength = 0;
		int isRushHour1 = 0;
		int isRushHour2 = 0;
		cin >> nodeA >> nodeB >> edgeLength >> isRushHour1 >> isRushHour2;
		Edge edgeAtoB(nodeB, edgeLength, isRushHour1);
		Edge edgeBtoA(nodeA, edgeLength, isRushHour2);
		adjList.at(nodeA).push_back(edgeAtoB);
		adjList.at(nodeB).push_back(edgeBtoA);
	}

	int maxTime = 0;
	for (int i = 1; i <= nNode; ++i){
		vector<int>visitedNode(nNode + 1, 0);
		double time = 0;
		dfs(adjList, visitedNode, 1, i, 0, time);
		if (time > maxTime){
			maxTime = time;
		}
	}

	cout << maxTime << endl;

	return 0;
}