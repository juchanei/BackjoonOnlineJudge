#include <iostream>
using namespace std;
int main(){
	int theNumber = 0;
	cin >> theNumber;
	int shellMax = 1;
	int count = 0;
	while (1){
		++count;
		if (theNumber <= shellMax) break;
		shellMax += ((count-1) * 6 + 6);
	}
	cout << count << endl;
	return 0;
}