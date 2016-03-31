#include <iostream>
#include <vector>
using namespace std;

vector<int> rooms;
vector<vector<int> > cache;
int roomsPerTrain;

int max(int a, int b)
{
	return a < b ? b : a;
}

int recu(int here, int count)
{
	if (3 == count) {
		return 0;
	}
	if (0 != cache[here][count]) {
		return cache[here][count];
	}

	int sum = 0;
	for (int i = 0; i < roomsPerTrain; ++i) {
		sum += rooms[here + i];
	}

	int maxResult = 0;
	if (here + roomsPerTrain - 1 < rooms.size()) {
		maxResult = max(maxResult, recu(here + roomsPerTrain, count + 1) + sum);
	}
	if (count < 3 && here + roomsPerTrain * (3 - count) < rooms.size()) {
		maxResult = max(maxResult, recu(here + 1, count));
	}

	cache[here][count] = maxResult;

	return maxResult;
}

int main()
{
	int nRoom;
	cin >> nRoom;

	rooms.assign(nRoom, 0);
	cache.assign(nRoom, vector<int>(4, 0));
	for (int i = 0; i < nRoom; ++i) {
		cin >> rooms[i];
	}

	cin >> roomsPerTrain;

	cout << recu(0, 0) << endl;

	return  0;
}