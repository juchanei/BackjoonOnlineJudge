#include <iostream>
using namespace std;

int clients[100002][2];

const int DIR[5][2] = {
	0, -1,
	0, 1,
	-1, 0,
	1, 0,
	0, 0
};

int getDistance(int x1, int y1, int x2, int y2)
{
	int diffx = x1 > x2 ? x1 - x2 : x2 - x1;
	int diffy = y1 > y2 ? y1 - y2 : y2 - y1;
	return diffx + diffy;
}

int main()
{
	int nClient;
	cin >> nClient;
	for (int i = 0; i < nClient + 1; ++i){
		cin >> clients[i][0];
		cin >> clients[i][1];
	}

	long long int count = 0;
	int prex = clients[0][0];
	int prey = clients[0][1];
	for (int i = 1; i <= nClient; ++i){
		int minValue = 200001;
		int minx = 0;
		int miny = 0;
		for (int j = 0; j < 5; ++j)
		{
			int distance = getDistance(prex, prey, clients[i][0] + DIR[j][0], clients[i][1] + DIR[j][1]);
			if (minValue > distance){
				minValue = distance;
				minx = clients[i][0] + DIR[j][0];
				miny = clients[i][1] + DIR[j][1];
			}
		}
		prex = minx;
		prey = miny;
		count += minValue;
	}

	cout << count << endl;

	return 0;
}