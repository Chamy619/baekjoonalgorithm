#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;

// 0µ¿ 1¼­ 2³² 3ºÏ
vector<vector<int>> slide(vector<vector<int>> board, int direction) {
	vector<vector<int>> result = board;
	switch (direction) {
	case 0:
		for (int y = 0;y < N; y++) {
			for (int x = N - 1; x > 0; x--) {
				if (result[y][x] == 0) {
					for (int t = x - 1; t >= 0; t--) {
						if (result[y][t] != 0) {
							swap(result[y][x], result[y][t]);
							break;
						}
					}
				}
			}
		}
		break;
	case 1:
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N - 1; x++) {
				if (result[y][x] == 0) {
					for (int t = x + 1; t < N; t++) {
						if (result[y][t] != 0) {
							swap(result[y][x], result[y][t]);
							break;
						}
					}
				}
			}
		}
		break;
	case 2:
		for (int x = 0; x < N; x++) {
			for (int y = N - 1; y > 0; y--) {
				if (result[y][x] == 0) {
					for (int t = y - 1; t >= 0; t--) {
						if (result[t][x] != 0) {
							swap(result[y][x], result[t][x]);
							break;
						}
					}
				}
			}
		}
		break;
	case 3:
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N - 1; y++) {
				if (result[y][x] == 0) {
					for (int t = y + 1; t < N; t++) {
						if (result[t][x] != 0) {
							swap(result[y][x], result[t][x]);
							break;
						}
					}
				}
			}
		}
		break;
	}

	return result;
}

//0µ¿ 1¼­ 2³² 3ºÏ
vector<vector<int>> move(vector<vector<int>> board, int direction) {
	vector<vector<int>> result = slide(board, direction);
	switch (direction) {
	case 0:
		for (int y = 0; y < N; y++) {
			for (int x = N - 1; x > 0; x--) {
				if (result[y][x] == result[y][x - 1]) {
					result[y][x] *= 2;
					result[y][x - 1] = 0;
					x--;
				}
			}
		}
		break;
	case 1:
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N - 1; x++) {
				if (result[y][x] == result[y][x + 1]) {
					result[y][x] *= 2;
					result[y][x + 1] = 0;
					x++;
				}
			}
		}
		break;
	case 2:
		for (int x = 0; x < N; x++) {
			for (int y = N - 1; y > 0; y--) {
				if (result[y][x] == result[y - 1][x]) {
					result[y][x] *= 2;
					result[y - 1][x] = 0;
					y--;
				}
			}
		}
		break;
	case 3:
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N - 1; y++) {
				if (result[y][x] == result[y + 1][x]) {
					result[y][x] *= 2;
					result[y + 1][x] = 0;
					y++;
				}
			}
		}
		break;
	}

	return slide(result, direction);
}

int maxNum(vector<vector<int>> board) {
	int result = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			result = max(result, board[y][x]);
		}
	}

	return result;
}

void show(vector<vector<int>> board) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int backtracking(vector<vector<int>> board, int cnt) {
	if (cnt == 5) {
		return maxNum(board);
	}

	int result = 0;
	for (int d = 0; d < 4; d++) {
		vector<vector<int>> temp = move(board, d);
		result = max(result, backtracking(temp, cnt + 1));
	}

	return result;
}

int main() {
	vector<vector<int>> board;
	cin >> N;
	for (int y = 0; y < N; y++) {
		vector<int> t;
		for (int x = 0; x < N; x++) {
			int temp;
			cin >> temp;
			t.push_back(temp);
		}
		board.push_back(t);
	}
	
	cout << backtracking(board, 0) << endl;
}