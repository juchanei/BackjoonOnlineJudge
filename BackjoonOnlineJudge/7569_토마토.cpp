#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int DIR[6][3] = {
	1, 0, 0,
	-1, 0, 0,
	0, 1, 0,
	0, -1, 0,
	0, 0, 1,
	0, 0, -1
};

struct Node
{
	int x, y, z, count;
	Node(int x, int y, int z, int count) : x(x), y(y), z(z), count(count) {}
	Node() : x(0), y(0), z(0), count(0) {}
};

int width, height, depth;
int remainTomato;
vector<vector<vector<int> > > tomatos;
queue<Node> qq;

int bfs()
{
	Node here;
	while (!qq.empty()) {
		here = qq.front();
		qq.pop();
		--remainTomato;
		for (int i = 0; i < 6; ++i) {
			if (0 == tomatos[here.y + DIR[i][1]][here.x + DIR[i][0]][here.z + DIR[i][2]]) {
				tomatos[here.y + DIR[i][1]][here.x + DIR[i][0]][here.z + DIR[i][2]] = 1;
				qq.push(Node(here.x + DIR[i][0], here.y + DIR[i][1], here.z + DIR[i][2], here.count + 1));
			}
		}
	}

	return here.count;
}

int main()
{
	cin >> width >> height >> depth;

	tomatos.assign(height + 2, vector<vector<int> >(width + 2, vector<int>(depth + 2, -1)));

	remainTomato = 0;
	for (int k = 1; k < tomatos[0][0].size() - 1; ++k) {
		for (int i = 1; i < tomatos.size() - 1; i++) {
			for (int j = 1; j < tomatos[i].size() - 1; j++) {
				cin >> tomatos[i][j][k];
				if (1 == tomatos[i][j][k]) {
					qq.push(Node(j, i, k, 0));
					++remainTomato;
				}
				else if (0 == tomatos[i][j][k]) {
					++remainTomato;
				}
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