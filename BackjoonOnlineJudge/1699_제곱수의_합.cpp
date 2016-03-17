#include <iostream>
using namespace std;

struct Node{
	int value;
	int count;
	Node(int value, int count)
		:value(value), count(count) { }
	Node()
		:value(0), count(0) { }
};

Node queuearr[100001];

struct queue{
	int head;
	int rear;
	queue()
		:head(0), rear(0) { }
	void push(Node data)
	{
		queuearr[rear] = data;
		++rear;
	}
	Node front()
	{
		Node data = queuearr[head];
		++head;
		return data;
	}
	void pop() {}
	bool empty()
	{
		if (head == rear)	return true;
		return false;
	}
};

int bfs(int theNumber)
{
	int visited[100001] = { 0, };
	Node startNode(0, 0);
	queue qq;
	qq.push(startNode);
	visited[0] = 0;

	while (!qq.empty()){
		Node here = qq.front();
		qq.pop();

		if (here.value == theNumber){
			return here.count;
		}
		
		for (int i = 1; i*i <= theNumber; ++i){
			if (here.value + i*i <= theNumber && 0 == visited[here.value + i*i]){
				Node next(here.value + i*i, here.count + 1);
				qq.push(next);
				visited[next.value] = next.count;
			}
		}
	}
}

int main()
{
	int theNumber;
	cin >> theNumber;

	cout << bfs(theNumber) << endl;

	return 0;
}