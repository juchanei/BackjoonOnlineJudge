#include <iostream>
#include <cstdio>
using namespace std;

int map[1002][1002] = { 0, };

int main()
{
	int height, width;
	cin >> height >> width;

	scanf("\n");
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			char temp;
			scanf("%c", &temp);
			map[i][j] = temp - '0';
		}
		scanf("\n");
	}

	int maxSquareSize = 0;
	for (int i = 2; i <= height; i++) {
		for (int j = 2; j <= width; j++) {
			if (0 == map[i][j]) continue;

			int minSize = map[i - 1][j];
			if (map[i][j - 1] < minSize)
				minSize = map[i][j - 1];
			if (map[i - 1][j - 1] < minSize)
				minSize = map[i - 1][j - 1];

			map[i][j] = minSize + 1;

			if (maxSquareSize < map[i][j]){
				maxSquareSize = map[i][j];
			}
		}
	}

	cout << maxSquareSize * maxSquareSize << endl;
	
	return 0;
}