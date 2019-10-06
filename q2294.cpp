#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

int n;
vector<int> dp;
vector<int> coin;

int coinNumber(int k) {
	if (k == 0) {
		return 0;
	}
	if (k < coin[0]) {
		return MAX;
	}
	if (dp[k] != -1) {
		return dp[k];
	}
	
	int result = coinNumber(k - coin[0]) + 1;
	for (int i = 1; i < n; i++) {
		result = min(result, coinNumber(k - coin[i]) + 1);
	}

	dp[k] = result;
	cout << "k = " << k << endl;
	cout << "result = " << result << endl;
	return result;
}

int main() {
	int k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int money;
		cin >> money;
		coin.push_back(money);
	}
	dp.resize(k + 1, -1);
	sort(coin.begin(), coin.end());
	if (coinNumber(k) >= MAX) {
		cout << -1 << endl;
	}
	else {
		cout << coinNumber(k) << endl;
	}
}