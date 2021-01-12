#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	vector<int> result(t);

	for (int i = 0;i < t;i++) {
		int n, m;
		int cnt = 0;
		cin >> n >> m;
		for (int j = n;j <= m;j++) {
			string s = to_string(j);
			for (int k = 0;k < s.length();k++) {
				if (s[k] == '0') cnt++;
			}
		}
		result[i] = cnt;
	}

	for (auto x : result) {
		cout << x << endl;
	}
}