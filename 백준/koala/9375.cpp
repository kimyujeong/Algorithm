#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t, n;
	cin >> t;

	for (int i = 0;i < t;i++) {
		map<string, int> cloth;
		cin >> n;
		for (int j = 0;j < n;j++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (cloth.count(s2) == 0) {
				cloth[s2] = 1;
			}
			else {
				cloth[s2]++;
			}
		}
		int res = 1;
		for (auto it = cloth.begin();it != cloth.end();it++) {
			res *= (it->second + 1);
		}
		cout << res - 1 << "\n";
	}
}