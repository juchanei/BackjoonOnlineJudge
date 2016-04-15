#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int DIR[4][2] = {
	1, 0,
	-1, 0,
	0, 1,
	0, -1
};

struct Node
{
	int x, y, count;
	Node(int x, int y, int count) : x(x), y(y), count(count) {}
	Node() : x(0), y(0), count(0) {}
};

int width, height;
int remainTomato;
vector<vector<int> > tomatos;
queue<Node> qq;

int bfs()
{
	Node here;
	while (!qq.empty()) {
		here = qq.front();
		qq.pop();
		--remainTomato;

		for (int i = 0; i < 4; ++i) {
			if (0 == tomatos[here.y + DIR[i][1]][here.x + DIR[i][0]]) {
				tomatos[here.y + DIR[i][1]][here.x + DIR[i][0]] = 1;
				qq.push(Node(here.x + DIR[i][0], here.y + DIR[i][1], here.count + 1));
			}
		}
	}

	return here.count;
}

int main()
{
	cin >> width >> height;

	tomatos.assign(height + 2, vector<int>(width + 2, 8));

	remainTomato = 0;
	for (int i = 1; i < tomatos.size() - 1; i++) {
		for (int j = 1; j < tomatos[i].size() - 1; j++) {
			cin >> tomatos[i][j];
			if (1 == tomatos[i][j]) {
				qq.push(Node(j, i, 0));
				++remainTomato;
			}
			else if (0 == tomatos[i][j]) {
				++remainTomato;
			}
		}
	}

	int result = bfs();
	if (0 != remainTomato) {
		cout << -1 << endl;
		return 0;
	}
	cout << result << endl;

	return 0;
}