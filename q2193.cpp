#include <iostream>
#include <algorithm>
#define MAX 91
using namespace std;

long long dp[MAX][2];
int N;

long long pnary(int n, int digit) {
	if (n == 1) {
		return 1;
	}
	if (dp[n][digit] != -1) {
		return dp[n][digit];
	}
	
	long long result = 1;
	if (digit == 1) {
		result = pnary(n - 1, 0);
	}
	else {
		result = pnary(n - 1, 1) + pnary(n - 1, 0);
	}

	dp[n][digit] = result;

	return result;
}

int main() {
	cin >> N;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			dp[i][j] = -1;
		}
	}
	cout << pnary(N, 1) << endl;
}