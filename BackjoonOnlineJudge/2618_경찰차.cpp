#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct Position{
	int x;
	int y;
	Position(int x, int y) : x(x), y(y) {}
	Position() : x(0), y(0) {}
};

struct CacheUnit
{
	int ret;
	int next;
	CacheUnit(int ret, int next) :ret(ret), next(next) {}
	CacheUnit() :ret(-1), next(-1) {}
};

const int INF = 987654321;

vector<vector<int> > map;
vector<Position> positions;
vector<vector<CacheUnit > > cache;

int abs(int a)
{
	return 0 < a ? a : -a;
}

int getDistance(int index1, int index2)
{
	return abs(positions[index1].x - positions[index2].x) + abs(positions[index1].y - positions[index2].y);
}

CacheUnit dfs(int car1Index, int car2Index)
{
	int eventIndex = car1Index < car2Index? car2Index + 1 : car1Index + 1;
	if (eventIndex == positions.size()) {
		return CacheUnit(0, 0);
	}

	CacheUnit& ret = cache[car1Index][car2Index];
	if (-1 != ret.ret) {
		return ret;
	}

	int minValue = INF;
	int returnValue = 0;
	int choice = 0;
	returnValue = dfs(eventIndex, car2Index).ret + getDistance(eventIndex, car1Index);
	if (returnValue < minValue) {
		minValue = returnValue;
		choice = 1;
	}
	returnValue = dfs(car1Index, eventIndex).ret + getDistance(eventIndex, car2Index);
	if (returnValue < minValue) {
		minValue = returnValue;
		choice = 2;
	}

	ret = CacheUnit(minValue, choice);
	return ret;
}

void reconstruct(int car1Index, int car2Index)
{
	int next = cache[car1Index][car2Index].next;
	int eventIndex = car1Index < car2Index ? car2Index + 1 : car1Index + 1;

	if (-1 == next) {
		return;
	}
	printf("%d\n", next);

	if (1 == next) {
		reconstruct(eventIndex, car2Index);
	}
	else if (2 == next) {
		reconstruct(car1Index, eventIndex);
	}
}

int main()
{
	int mapSize, nEvent;
	cin >> mapSize >> nEvent;

	map.assign(mapSize + 1, vector<int>(mapSize + 1, 0));
	positions.assign(nEvent + 2, Position());
	cache.assign(nEvent + 2, vector<CacheUnit>(nEvent + 2, CacheUnit()));

	positions[0] = Position(1, 1);
	positions[1] = Position(mapSize, mapSize);
	for (int i = 2; i < positions.size(); ++i) {
		int xx, yy;
		scanf("%d %d\n", &xx, &yy);
		positions[i] = Position(xx, yy);
	}

	cout << dfs(0, 1).ret << endl;
	reconstruct(0, 1);

	return 0;
}