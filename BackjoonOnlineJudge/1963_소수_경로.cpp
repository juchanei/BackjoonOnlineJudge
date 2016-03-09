#include <iostream>
using namespace std;


struct Node{
	int value;
	int count;
	Node(int value, int count) :value(value), count(count) {}
	Node() :value(0), count(0) {}
};

Node queue[1000];
int front = 0;
int rear = 0;
bool primeArr[10000];

void enqueue(Node data)
{
	queue[rear] = data;
	++rear;
	return;
}

Node dequeue()
{
	Node returnValue = queue[front];
	++front;
	return returnValue;
}

bool isEmpty()
{
	if (front == rear)	return true;
	else return false;
}

void init()
{
	front = 0;
	rear = 0;
}

bool isPrime(int number)
{
	for (int i = 2; i < number; ++i){
		if (0 == number%i){
			return false;
		}
	}
	return true;
}

bool calcPrime(bool arr[10000])
{
	for (int i = 2; i < 10000; ++i){
		if (isPrime(i)){
			int pointer = i;
			int iter = 2;
			while (pointer * iter < 10000){
				arr[pointer * iter] = false;
				++iter;
			}
		}
	}

	return true;
}

int changeNumber(int number, int digit, int value)
{
	int temp = number;
	int pp = 1;
	for (int i = 0; i < digit; ++i){
		pp *= 10;
	}

	temp /= pp;
	temp %= 10;

	number -= pp * temp;
	number += pp * value;

	return number;
}

int bfs(const int start, const int dest)
{
	bool visitiedNode[10000] = { 0, };

	Node startNode(start, 0);
	enqueue(startNode);

	while (!isEmpty()){

		Node here = dequeue();

		if (here.value == dest){
			return here.count;
		}

		for (int i = 0; i < 4; ++i){
			for (int j = 0; j < 10; ++j){
				int temp = changeNumber(here.value, i, j);
				if (isPrime(temp) && 0 == visitiedNode[temp] && temp > 999){
					Node next(temp, here.count + 1);
					enqueue(next);
					visitiedNode[next.value] = true;
				}
			}
		}
	}
}

int main()
{
	int testcase = 0;
	cin >> testcase;

	for (int i = 1; i < 10000; ++i){
		primeArr[i] = true;
	}
	calcPrime(primeArr);

	while (testcase--){
		init();
		int start = 0;
		int dest = 0;
		cin >> start >> dest;

		cout << bfs(start, dest) << endl;
	}

	return 0;
}