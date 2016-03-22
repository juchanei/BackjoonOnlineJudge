#include <iostream>
#include <vector>
#include <map>
using namespace std;

int mapSize;
vector<vector<int> > chessmap;
map<vector<vector<int> >, int> cache;

void print()
{
	system("cls");
	for (int i = 1; i <= mapSize; i++){
		for (int j = 1; j <= mapSize; j++){
			cout << chessmap[i][j] << " ";
		}
		cout << endl;
	}
}

bool isBishop(int xx, int yy)
{
	int i = yy;
	int j = xx;
	while (i <= mapSize && j <= mapSize){
		if (3 == chessmap[i][j]){
			return true;
		}
		i++;
		j++;
	}
	i = yy;
	j = xx;
	while (0 < i && 0 < j){
		if (3 == chessmap[i][j]){
			return true;
		}
		i--;
		j--;
	}
	i = yy;
	j = xx;
	while (0 < i && j <= mapSize){
		if (3 == chessmap[i][j]){
			return true;
		}
		i--;
		j++;
	}
	i = yy;
	j = xx;
	while (i <= mapSize && 0 < j){
		if (3 == chessmap[i][j]){
			return true;
		}
		i++;
		j--;
	}

	return false;
}

void draw(int xx, int yy, int value)
{
	int i = yy;
	int j = xx;
	while (i <= mapSize && j <= mapSize){
		if (0 != chessmap[i][j]){
			chessmap[i][j] = value;
		}
		i++;
		j++;
	}
	i = yy;
	j = xx;
	while (0 < i && 0 < j){
		if (0 != chessmap[i][j]){
			chessmap[i][j] = value;
		}
		i--;
		j--;
	}
	i = yy;
	j = xx;
	while (0 < i && j <= mapSize){
		if (0 != chessmap[i][j]){
			chessmap[i][j] = value;
		}
		i--;
		j++;
	}
	i = yy;
	j = xx;
	while (i <= mapSize && 0 < j){
		if (0 != chessmap[i][j]){
			chessmap[i][j] = value;
		}
		i++;
		j--;
	}
}

int dfs(int xx, int yy)
{
	draw(xx, yy, 3);

	//if (0 != cache[chessmap]){
	//	chessmap[yy][xx] = 1;
	//	return cache[chessmap];
	//}

	int max = 0;
	for (int i = 1; i <= mapSize; i++){
		for (int j = 1; j <= mapSize; j++){
			if (1 == chessmap[i][j]/* && !isBishop(j, i)*/){
				int temp = dfs(j, i);
				if (max < temp){
					max = temp;
				}
			}
		}
	}

	//cache[chessmap] = max + 1;
	draw(xx, yy, 1);
	return max + 1;
}

int main()
{
	cin >> mapSize;
	chessmap.assign(mapSize + 2, vector<int>(mapSize + 2, 0));

	for (int i = 1; i <= mapSize; i++){
		for (int j = 1; j <= mapSize; j++){
			cin >> chessmap[i][j];
		}
	}

	int max = 0;
	for (int i = 1; i <= mapSize; i++){
		for (int j = 1; j <= mapSize; j++){
			if (0 != chessmap[i][j]){
				int temp = dfs(j, i);
				if (max < temp){
					max = temp;
				}
			}
		}
	}

	cout << max << endl;

	return 0;
}