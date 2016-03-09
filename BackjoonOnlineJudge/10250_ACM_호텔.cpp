#include <iostream>
using namespace std;

int main()
{
	int tc = 0;
	cin >> tc;
	while (tc--){
		int hh = 0;
		int ww = 0;
		int nn = 0;
		cin >> hh >> ww >> nn;

		int a = nn%hh;
		int b = 0;
		if (a == 0){
			a = hh;
			b = nn / hh;
			if (b < 10){
				a *= 10;
			}
		}
		else{
			b = nn / hh + 1;
			if (b < 10){
				a *= 10;
			}
		}
		cout << a << b << endl;

	}
	return 0;
}