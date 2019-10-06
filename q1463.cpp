#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp;

int makeOne(int n) {
	if (dp[n] != 1000001) {
		return dp[n];
	}


	int result = 1000001;

	result = min(result, makeOne(n - 1)+1);
	if (n % 3 == 0) {
		result = min(result, makeOne(n / 3) + 1);
	}
	if (n % 2 == 0) {
		result = min(result, makeOne(n / 2) + 1);
	}

	dp[n] = result;
	return result;
}

int main() {
	int n;
	cin >> n;

	dp.resize(n+3, 1000001);
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	cout << makeOne(n) << endl;
}