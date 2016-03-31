#include <iostream>
#include <vector>
using namespace std;

vector<int> books;

int recu(int here)
{

}

int main()
{
	int tc;
	cin >> tc;
	while (tc--) {
		int nBook;
		cin >> nBook;
		books.assign(nBook, 0);
		for (int i = 0; i < nBook; +i) {
			cin >> books[i];
		}

		/*
		어느정도 정렬이 된 수열 아래로 책하나가 들어가려면 반복작업 발생
		이것을 캐싱하자

		불안정이되는 첫번째 수를 선택
		선택된 수를 맨위에 올리고 그보다 작은 안정된 수열을 올린다, 중간에 끼워넣는 꼴이 됨
		끼워 넣은 윗 부분이 같으면 항상 같은 카운트를 리턴


		*/

		cout << endl;
	}

	return 0;
}