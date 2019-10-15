#include <iostream>
#include <cstring>
#define MAX 1001
#define MOD 10007
using namespace std;

int dp[MAX];

int tiling(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 3;
	}
	if (dp[n] != -1) {
		return dp[n];
	}

	int result = 0;
	result = 2 * tiling(n - 2) + tiling(n - 1);
	result %= MOD;

	dp[n] = result;
	return result;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	cout << tiling(n) << endl;

}