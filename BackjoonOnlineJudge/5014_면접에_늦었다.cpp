#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maxFloor, currentFloor, targetFloor, up, down;
struct Node{
	int first;
	int second;
	Node(int first, int second) :first(first), second(second) {};
};

int bfs()
{
	queue<Node> qq;
	vector<bool> visited(maxFloor + 1, false);
	qq.push(Node(currentFloor, 0));
	visited[currentFloor] = true;

	while (!qq.empty()){
		Node here = qq.front();
		qq.pop();

		if (here.first == targetFloor){
			return here.second;
		}


		{
			int nextFloor = here.first + up;
			if (nextFloor <= maxFloor && 0 == visited[nextFloor]){
				Node next(nextFloor, here.second + 1);
				qq.push(next);
				visited[next.first] = 1;
			}
		};
		{
			int nextFloor = here.first - down;
			if (0 < nextFloor && 0 == visited[nextFloor]){
				Node next(here.first - down, here.second + 1);
				qq.push(next);
				visited[next.first] = 1;
			}
		};
	}

	return -1;
}

int main()
{
	cin >> maxFloor >> currentFloor >> targetFloor >> up >> down;

	int result = bfs();
	if (result == -1){
		cout << "use the stairs" << endl;
		return 0;
	}
	cout << result << endl;

	return 0;
}