#include <iostream>
using namespace std;

void addCharArr(char adder[11], int adderLen, int position, char out[21])
{
	int carry = 0;

	int i;
	for (i = 0; i < adderLen; ++i){
		int temp = (out[position + i] - '0') + (adder[i] - '0') + carry;
		out[position + i] = (temp % 10) + '0';
		carry = temp / 10;
	}

	for (i; 0 != carry; ++i){
		int temp = (out[position + i] - '0') + carry;
		out[position + i] = (temp % 10) + '0';
		carry = temp / 10;
	}
}

void multiplyCharArr(char in1[11], char in2[11], char out[21], int digit)
{
	for (int i = 0; i < digit * 2; ++i){
		out[i] = '0';
	}

	for (int i = 0; i < digit; ++i){
		int times = in2[i] - '0';
		for (int j = 0; j < times; ++j){
			addCharArr(in1, digit, i, out);
		}
	}
}

void getMax(char out[21], int digit)
{
	char in1[11] = { 0, };
	for (int i = 0; i < digit - 1; ++i){
		in1[i] = '9';
	}
	in1[digit - 1] = '4';

	char in2[11] = { 0, };
	for (int i = 0; i < digit - 1; ++i){
		in2[i] = '0';
	}
	in2[digit - 1] = '5';

	for (int i = 0; i < digit * 2; ++i){
		out[i] = '0';
	}

	multiplyCharArr(in1, in2, out, digit);
}

void getNbyFN(int theNumber, int digit, char out[21])
{
	char nn[11] = { 0, };
	for (int i = 0; i < digit; ++i){
		nn[i] = (theNumber % 10) + '0';
		theNumber /= 10;
	}

	char fn[11] = { 0, };
	for (int i = 0; i < digit; ++i){
		fn[i] = '9' - nn[i] + '0';
	}

	out[21] = { 0, };
	multiplyCharArr(nn, fn, out, digit);
}

int getDigit(int in)
{
	int count = 0;
	while (0 < in){
		in /= 10;
		++count;
	}
	return count;
}

bool charArrComp(char small[21], char big[21], int digit)
{
	int iter1 = digit * 2 - 1;
	while ('0' == big[iter1]) --iter1;
	int iter2 = digit * 2 - 1;
	while ('0' == small[iter2]) --iter2;

	int iter = iter1;
	if (iter1 < iter2)
		iter = iter2;

	for (int i = iter; 0 <= i; --i){
		if (small[i] < big[i])
			return true;
		else if (big[i] < small[i])
			return false;
	}
	return false;
}

void charArrCopy(char from[21], char to[21], int digit)
{
	for (int i = 0; i < digit * 2; ++i){
		to[i] = from[i];
	}
}

int power(int digit)
{
	int result = 1;
	for (int i = 1; i < digit; ++i){
		result *= 10;
	}
	return result;
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--){
		int theNumber;
		cin >> theNumber;

		int digit = getDigit(theNumber);

		//무작정 찾기
		{
			char max[21] = { 0, };
			for (int i = power(digit); i <= theNumber; ++i){
				char out[21] = { 0, };
				int tempDigit = getDigit(i);
				getNbyFN(i, tempDigit, out);

				if (charArrComp(max, out, digit)){
					charArrCopy(out, max, digit);
				}
			}
			int iter = digit * 2 - 1;
			while ('0' == max[iter]) --iter;
			for (int i = iter; 0 <= i; --i){
				cout << max[i];
			}
			cout << endl;
		}

		//경우 나눠서 찾기
		{
			char out[21] = { 0, };
			int base = power(digit) * 5;
			if (base < theNumber){
				getMax(out, digit);
			}
			else{
				getNbyFN(theNumber, digit, out);
			}
			int xx = digit * 2 - 1;
			while ('0' == out[xx]) --xx;
			for (int i = xx; 0 <= i; --i){
				cout << out[i];
			}
			cout << endl;
		}
	}
	return 0;
}