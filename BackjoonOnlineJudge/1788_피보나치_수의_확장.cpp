#include <iostream>
using namespace std;

int cache[1000001] = { 0, };

int main()
{
	cache[0] = 0;
	cache[1] = 1;
	for (int i = 2; i < 1000001; i++){
		cache[i] = (cache[i - 1] + cache[i - 2]) % 1000000000;
	}

	int theNumber;
	cin >> theNumber;
	if (0 == theNumber){
		cout << 0 << endl;
	}
	else if (0 < theNumber){
		cout << 1 << endl;
	}
	else if (theNumber < 0){
		theNumber *= -1;
		if (0 == theNumber % 2){
			cout << -1 << endl;
		}
		else{
			cout << 1 << endl;
		}
	}
	cout << cache[theNumber] << endl;

	return 0;
}