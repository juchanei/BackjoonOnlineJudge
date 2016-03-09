#include <iostream>
#include <queue>
using namespace std;

struct circle{
	int left;
	int right;
};

circle circles[300001] = { 0, };
int visited[300001] = { 0, };

bool isBisectable(int start, int nCircle)
{
	bool flag = false;
	queue<int> qq;
	visited[start] = 1;
	int targetRight = circles[start].right;

	for (int i = 0; i < nCircle; ++i){
		if (circles[start].left == circles[i].left && 0 == visited[i]){
			qq.push(i);
			visited[i] = 1;
		}
	}


	while (!qq.empty()){
		int here = qq.front();
		qq.pop();

		if (circles[here].right == targetRight){
			flag = true;
			break;
		}

		for (int i = 0; i < nCircle; ++i){
			if (circles[here].right == circles[i].left && 0 == visited[i]){
				qq.push(i);
				visited[i] = 1;
			}
		}
	}

	for (int i = 0; i < nCircle; ++i){
		visited[i] = 0;
	}

	if (true == flag){
		return true;
	}
	return false;
}


int main()
{
	int nCircle = 0;
	cin >> nCircle;
	for (int i = 0; i < nCircle; ++i){
		int midpoint = 0;
		int radius = 0;
		cin >> midpoint >> radius;

		circles[i].left = midpoint - radius;
		circles[i].right = midpoint + radius;
	}

	int result = nCircle + 1;
	for (int i = 0; i < nCircle; ++i){
		int left = circles[i].left;
		int right = circles[i].right;

		if (isBisectable(i, nCircle)){
			++result;
		}
	}

	cout << result << endl;

	return 0;
}