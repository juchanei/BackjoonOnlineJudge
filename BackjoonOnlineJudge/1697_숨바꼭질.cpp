#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	int position;
	int time;
	Node(int position, int time) :position(position), time(time) {}
	Node() :position(0), time(0) {}
};

int bfs(int start, int destination)
{
	vector<int> visited(2 * destination + 1, 0);
	queue<Node> qq;
	Node startNode(start, 0);
	qq.push(startNode);
	visited[startNode.position] = 1;

	while (!qq.empty()) {
		Node here = qq.front();
		qq.pop();

		if (here.position == destination) {
			return here.time;
		}

		{
			if (0 <= here.position - 1 && 0 == visited[here.position - 1]) {
				Node next(here.position - 1, here.time + 1);
				visited[next.position] = 1;
				qq.push(next);
			}
		};
		{
			if (here.position + 1 < visited.size() && 0 == visited[here.position + 1]) {
				Node next(here.position + 1, here.time + 1);
				visited[next.position] = 1;
				qq.push(next);
			}
		};
		{
			if (here.position * 2 < visited.size() && 0 == visited[here.position * 2]) {
				Node next(here.position * 2, here.time + 1);
				visited[next.position] = 1;
				qq.push(next);
			}
		};
	}

	return 0;
}

int main()
{
	int start, destination;
	cin >> start >> destination;

	if (destination < start) {
		cout << start - destination << endl;
		return 0;
	}

	cout << bfs(start, destination) << endl;

	return 0;
}