#include <iostream>
#include <vector>
using namespace std;

vector<int> leftCards, rightCards;
vector<vector<int> > cache;

int max(int a, int b)
{
	return a < b ? b : a;
}

int recu(int leftCardIndex, int rightCardIndex)
{
	int& ret = cache[leftCardIndex][rightCardIndex];
	if (-1 != ret) {
		return ret;
	}
	if (leftCardIndex == leftCards.size()
		|| rightCardIndex == rightCards.size()) {
		return 0;
	}

	int maxValue = 0;
	if (leftCardIndex <= leftCards.size()) {
		//왼쪽버림
		maxValue = max(maxValue, recu(leftCardIndex + 1, rightCardIndex));
	}
	if (leftCardIndex <= leftCards.size() && rightCardIndex <= rightCards.size()) {
		//양쪽버림
		maxValue = max(maxValue, recu(leftCardIndex + 1, rightCardIndex + 1));
	}
	if (rightCards[rightCardIndex] < leftCards[leftCardIndex] && rightCardIndex <= rightCards.size()) {
		//오른쪽 버리고 점수얻기
		maxValue = max(maxValue, recu(leftCardIndex, rightCardIndex + 1) + rightCards[rightCardIndex]);
	}

	ret = maxValue;
	return ret;
}

int main()
{
	int nCard;
	cin >> nCard;

	leftCards.assign(nCard, 0);
	rightCards.assign(nCard, 0);
	cache.assign(nCard + 1, vector<int>(nCard + 1, -1));

	for (int i = 0; i < leftCards.size(); ++i) {
		cin >> leftCards[i];
	}
	for (int i = 0; i < rightCards.size(); ++i) {
		cin >> rightCards[i];
	}

	cout << recu(0, 0) << endl;

	return 0;
}