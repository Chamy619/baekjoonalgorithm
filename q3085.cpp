#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int numCandy(vector<string> board) {
	int count = 1;

	//가로
	for (int i = 0; i < board.size(); i++) {
		int temp = 1;
		for (int j = 1; j < board.size(); j++) {
			if (board[i][j] == board[i][j - 1]) {
				temp++;
			}
			else {
				count = max(count, temp);
				temp = 1;
			}
		}
		count = max(count, temp);
	}

	//세로
	for (int j = 0; j < board.size(); j++) {
		int temp = 1;
		for (int i = 1; i < board.size(); i++) {
			if (board[i][j] == board[i - 1][j]) {
				temp++;
			}
			else {
				count = max(count, temp);
				temp = 1;
			}
		}
		count = max(count, temp);
	}

	return count;
}


int main() {
	int n;
	cin >> n;
	vector<string> board;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		board.push_back(temp);
	}

	int result = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			swap(board[i][j], board[i][j + 1]);
			result = max(result, numCandy(board));
			swap(board[i][j], board[i][j + 1]);

			swap(board[j][i], board[j+1][i]);
			result = max(result, numCandy(board));
			swap(board[j][i], board[j + 1][i]);
		}
	}
	cout << result << endl;
}