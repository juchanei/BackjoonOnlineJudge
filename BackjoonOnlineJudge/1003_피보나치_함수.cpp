#include <iostream>
#include <vector>
using namespace std;

struct Result
{
	int zero;
	int one;
	Result(int zero, int one) :zero(zero), one(one) {}
	Result() :zero(-1), one(-1) {}
	Result operator+(const Result& rhs)
	{
		return Result(this->zero + rhs.zero, this->one + rhs.one);
	}
};

vector<Result> cache;

Result fibonacci(int n)
{
	Result& ret = cache[n];
	if (-1 != ret.one && -1 != ret.zero) {
		return ret;
	}
	if (n == 0) {
		return Result(1, 0);
	}
	else if (n == 1) {
		return Result(0, 1);
	}

	ret = fibonacci(n - 1) + fibonacci(n - 2);
	return ret;
}

int main()
{
	int tc;
	cin >> tc;

	while(tc--) {
		int n;
		cin >> n;

		cache.assign(n + 1, Result());
		Result result = fibonacci(n);
		cout << result.zero << " " << result.one << endl;
	}

	return 0;
}