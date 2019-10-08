#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000
using namespace std;

int N;
int A[MAX];
int dp[MAX];

int lis(int n, vector<int>& lisList) {
	if (n >= N) {
		return 0;
	}
	if (dp[n] != -1) {
		return dp[n];
	}

	int result = A[n];

	for (int i = n; i < N; i++) {
		if (A[i] > A[n]) {
			lisList.push_back(A[i]);
			result = max(result, lis(i, lisList) + A[n]);
			lisList.pop_back();
		}
	}

	dp[n] = result;
	return result;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		dp[i] = -1;
	}
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<int> lisList;
	int result = lis(0, lisList);
	for (int i = 1; i < N; i++) {
		result = max(result, lis(i, lisList));
	}
	cout << result << endl;
}