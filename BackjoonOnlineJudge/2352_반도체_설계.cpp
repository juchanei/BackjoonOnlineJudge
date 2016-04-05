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
vector<int> connectedPort;

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

int recu(int portIndex)
{
	if (portIndex == portConnections.size()) {
		return 0;
	}

	int maxValue = 0;
	bool isCross = false;
	for (int i = 1; i < portIndex; ++i) {
		if (isCrossWith(portIndex, i) && 1 == connectedPort[i]) {
			isCross = true;
			break;
		}
	}
	if (false == isCross) {
		connectedPort[portIndex] = 1;
		maxValue = max(maxValue, recu(portIndex + 1) + 1);
	}
	connectedPort[portIndex] = 0;
	maxValue = max(maxValue, recu(portIndex + 1));

	return maxValue;
}

int main()
{
	int nPort;
	cin >> nPort;

	portConnections.assign(nPort + 1, Connection());
	connectedPort.assign(nPort + 1, 0);
	for (int i = 1; i < portConnections.size(); ++i) {
		portConnections[i].from = i;
		cin >> portConnections[i].to;
	}

	cout << recu(1) << endl;

	return 0;
}