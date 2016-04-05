#include <iostream>
#include <vector>
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
vector<Position> events;
vector<vector<CacheUnit > > cache;

int abs(int a)
{
	return 0 < a ? a : -a;
}

CacheUnit dfs(int car1Index, int car2Index)
{
	int eventIndex = car1Index < car2Index? car2Index + 1 : car1Index + 1;
	if (eventIndex == events.size()) {
		return CacheUnit(0, 0);
	}

	CacheUnit& ret = cache[car1Index][car2Index];
	if (-1 != ret.ret) {
		return ret;
	}

	Position car1 = events[car1Index];
	Position car2 = events[car2Index];
	Position event = events[eventIndex];
	int car1EventDistance = abs(event.x - car1.x) + abs(event.y - car1.y);
	int car2EventDistance = abs(event.x - car2.x) + abs(event.y - car2.y);

	int minValue = INF;
	int returnValue = 0;
	int choice = 0;
	returnValue = dfs(eventIndex, car2Index).ret + car1EventDistance;
	if (returnValue < minValue) {
		minValue = returnValue;
		choice = 1;
	}
	returnValue = dfs(car1Index, eventIndex).ret + car2EventDistance;
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
	cout << next << endl;

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
	events.assign(nEvent + 2, Position());
	cache.assign(nEvent + 2, vector<CacheUnit>(nEvent + 2, CacheUnit()));

	events[0] = Position(1, 1);
	events[1] = Position(mapSize, mapSize);
	for (int i = 2; i < events.size(); ++i) {
		int xx, yy;
		cin >> xx >> yy;
		events[i] = Position(xx, yy);
	}

	cout << dfs(0, 1).ret << endl;
	reconstruct(0, 1);

	return 0;
}