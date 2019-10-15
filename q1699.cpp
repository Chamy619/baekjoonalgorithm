#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 999999999
#define MAX 100001
using namespace std;

vector<int> squareNum;
int dp[MAX];

void square(int n) {
	for (int i = 0; i * i <= n; i++) {
		squareNum.push_back(i*i);
	}
}

int squareSum(int n) {
	if (n == 0) {
		return 0;
	}
	if (dp[n] != -1) {
		return dp[n];
	}

	int result = INF;
	for (int i = squareNum.size() - 1; i > 0; i--) {
		if (n < squareNum[i]) {
			continue;
		}
		result = min(result, 1 + squareSum(n - squareNum[i]));
	}

	dp[n] = result;
	return result;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	square(n);
	cout << squareSum(n) << endl;
}