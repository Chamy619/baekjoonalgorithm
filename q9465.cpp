#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int N, board[2][MAX], dp[MAX][3];

int sticker(int c, int status) {
	if (c == N) {
		return 0;
	}
	if (dp[c][status] != -1) {
		return dp[c][status];
	}

	int result = sticker(c + 1, 0);
	if (status != 1) {
		result = max(result, sticker(c + 1, 1) + board[0][c]);
	}
	if (status != 2) {
		result = max(result, sticker(c + 1, 2) + board[1][c]);
	}

	dp[c][status] = result;
	return result;
}

int main() {
	int T;
	cin >> T;
	while (T > 0) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 3; j++) {
				dp[i][j] = -1;
			}
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
			}
		}
		cout << sticker(0, 0) << endl;
		T--;
	}
}