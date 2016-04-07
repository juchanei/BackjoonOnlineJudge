#include <iostream>
#include <vector>
using namespace std;

struct Connection
{
	int from;
	int to;
	Connection(int from, int to) : from(from), to(to) {}
	Connection() : from(0), to(0) {}
};

vector<Connection> portConnections;
vector<int> cache;

bool isCrossWith(int index1, int index2)
{
	int diff1 = portConnections[index1].from - portConnections[index2].from;
	int diff2 = portConnections[index1].to - portConnections[index2].to;
	return diff1 * diff2 < 0 ? true : false;
}

int max(int a, int b)
{
	return a < b ? b : a;
}

int recu(int currentIndex)
{
	int& ret = cache[currentIndex];
	if (-1 != ret) {
		return ret;
	}

	int maxValue = 0;
	for (int i = currentIndex + 1; i < portConnections.size() && i < currentIndex + 100; ++i) {
		if (!isCrossWith(currentIndex, i)) {
			maxValue = max(maxValue, recu(i) + 1);
		}
	}

	ret = maxValue;
	return maxValue;
}

int main()
{
	int nPort;
	cin >> nPort;

	portConnections.assign(nPort + 1, Connection());
	cache.assign(nPort + 1, -1);

	for (int i = 1; i < portConnections.size(); ++i) {
		portConnections[i].from = i;
		cin >> portConnections[i].to;
	}

	cout << recu(0) << endl;

	return 0;
}

/*
	보통 lis처럼 현재 인덱스에서 끝까지 탐색하면 40000x40000에 가까운 반복이 있다
	현재 인덱스에서 대략 100개정도만 탐색해도 답이 나오는 문제.
*/