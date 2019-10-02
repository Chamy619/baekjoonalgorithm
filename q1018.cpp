#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int change(vector<string> board, int y, int x) {
	int count = 0;
	for (int i = y; i < y + 7; i++) {
		for (int j = x; j < x + 7; j++) {
			if (board[i][j] == board[i + 1][j]) {
				board[i + 1][j] = (board[i + 1][j] == 'W') ? 'B' : 'W';
				count++;
			}
			if (board[i][j] == board[i][j + 1]) {
				board[i][j + 1] = (board[i][j + 1] == 'W') ? 'B' : 'W';
				count++;
			}
		}
	}

	return min(count, 64 - count);
}

int main() {
	vector<string> board;
	int m, n;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		board.push_back(temp);
	}

	int result = 80;
	
	for (int cutN = 0; cutN <= n - 8; cutN++) {
		for (int cutM = 0; cutM <= m - 8; cutM++) {
			int count = change(board, cutN, cutM);
			result = min(result, count);
		}
	}

	cout << result << endl;
}