#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int value;
	bool found;
	Node(int value, bool found) :value(value), found(found) {}
	Node() :value(0), found(0) {}
};


int nSocket, nPlug;
vector<Node> sockets(nSocket, Node(0, 0));

void dfs(int plugIndex)
{

	for (int i = 0;)

}

int main()
{
	int nSocket, nPlug;
	cin >> nSocket >> nPlug;

	int plugs[101] = { 0, };
	for (int i = 0; i < nPlug; ++i)
	{
		cin >> plugs[i];
	}
	
	vector<Node> sockets(nSocket, Node(0, 0));

	for (int i = 0; i < nSocket; ++i)
	{
		sockets[i].value = plugs[i];
	}



	return 0;
}