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
		������� ������ �� ���� �Ʒ��� å�ϳ��� ������ �ݺ��۾� �߻�
		�̰��� ĳ������

		�Ҿ����̵Ǵ� ù��° ���� ����
		���õ� ���� ������ �ø��� �׺��� ���� ������ ������ �ø���, �߰��� �����ִ� ���� ��
		���� ���� �� �κ��� ������ �׻� ���� ī��Ʈ�� ����


		*/

		cout << endl;
	}

	return 0;
}