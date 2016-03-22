#include <iostream>
using namespace std;

int getGCD(int a, int b)
{
	while (b != 0){
		int mod = a%b;
		a = b;
		b = mod;
	}
	return a;
}

int main()
{
	int numA, denA, numB, denB;
	cin >> numA >> denA >> numB >> denB;

	int numAB = numA * denB + numB * denA;
	int denAB = denA * denB;

	int gcd = getGCD(numAB, denAB);
	numAB /= gcd;
	denAB /= gcd;

	cout << numAB << " " << denAB << endl;

	return 0;
}