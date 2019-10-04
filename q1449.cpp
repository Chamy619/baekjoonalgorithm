#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, L;
	cin >> N >> L;
	vector<int> point;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		point.push_back(temp);
	}

	sort(point.begin(), point.end());

	int count = 0;
	int tape = 0;

	for (int i = 0; i < N; i++) {
		if (point[i] > tape) {
			count++;
			tape = point[i] + L - 1;
		}
	}

	cout << count << endl;
}