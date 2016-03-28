#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int getLCM(vector<int> arr)
{
	sort(arr.begin(), arr.end());
	int result = arr[arr.size() - 1];

	while (1){
		int count = 0;
		for (int i = 1; i < arr.size(); ++i){
			if (0 == result % arr[i]){
				count++;
			}
			else{
				result++;
				break;
			}
		}
		if (arr.size() - 1 == count){
			return result;
		}
	}
}

int main()
{
	int nChildren, nRide;
	cin >> nChildren >> nRide;
	vector<int> playtime(nRide + 1, 0);
	for (int i = 1; i < playtime.size(); ++i){
		cin >> playtime[i];
	}
	int lcmTime = getLCM(playtime);

	int child = 1;
	vector<int> order(1, 1);
	for (child = 1; child < playtime.size(); ++child){
		order.push_back(child);
	}
	for (int i = 1; i < lcmTime; ++i){
		for (int j = 1; j < playtime.size(); ++j){
			if (0 == i % playtime[j]){
				order.push_back(j);
				child++;
			}
		}
	}
	child--;

	int remain = nChildren % child;
	cout << order[remain] << endl;

	return 0;
}