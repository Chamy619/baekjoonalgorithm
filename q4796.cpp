#include <iostream>
#include <vector>
using namespace std;

int main() {
	int L, P, V;
	vector<int> res;
	
	cin >> L >> P >> V;

	while (L != 0) {
		int nam;
		if (V%P > L) {
			nam = L;
		}
		else {
			nam = V%P;
		}
		int result = nam + V / P*L;
		res.push_back(result);

		cin >> L >> P >> V;
	}

	for (int i = 0; i < res.size(); i++) {
		cout << "Case " << i + 1 << ": " << res[i] << endl;
	}
}