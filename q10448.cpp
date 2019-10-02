#include <iostream>
#include <vector>
using namespace std;

int eureka(int n) {
	return n*(n + 1) / 2;
}

int main() {
	int t;
	cin >> t;
	for (int test = 0; test < t; test++) {
		int n;
		cin >> n;
		vector<int> eurekaNum;
		int temp = 1;
		while (eureka(temp) < n) {
			eurekaNum.push_back(eureka(temp));
			temp++;
		}

		bool result = false;

		for (int i = 0; i < eurekaNum.size(); i++) {
			for (int j = 0; j < eurekaNum.size(); j++) {
				for (int k = 0; k < eurekaNum.size(); k++) {
					if (eurekaNum[i] + eurekaNum[j] + eurekaNum[k] == n) {
						result = true;
						break;
					}
				}
			}
		}
		cout << result << endl;
	}
}