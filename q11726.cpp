#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1001
#define MOD 10007
using namespace std;

int N, dp[MAX];

int tiling(int n) {
	if (n == 1 || n == 2) {
		return n;
	}
	if (dp[n] != -1) {
		return dp[n];
	}

	int result = 0;
	result = (tiling(n - 1) % MOD + tiling(n - 2) % MOD) % MOD;
	
	dp[n] = result;
	return result;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cout << tiling(N) << endl;
}