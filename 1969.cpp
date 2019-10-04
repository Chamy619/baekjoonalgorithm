#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const char DNA[4] = { 'A','C','G','T' };

int main() {
	int N, M;
	vector<string> dna;
	string result = "";
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		dna.push_back(s);
	}

	int hamming = 0;
	
	for (int i = 0; i < M; i++) {
		int count[4] = { 0,0,0,0 };
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				if (dna[j][i] == DNA[k]) {
					count[k] += 1;
					break;
				}
			}
		}

		int max = count[0];
		int loc = 0;

		for (int t = 1; t < 4; t++) {
			if (max < count[t]) {
				max = count[t];
				loc = t;
			}
		}
		hamming += N - max;
		result.push_back(DNA[loc]);
	}

	cout << result << endl;
	cout << hamming << endl;
}