#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

	while (1) {
		string s;
		cin >> s;

		if (s == "*") break;

		bool flag = false;

		for (int i = 1;i <= s.size() - 1;i++) {
			map<string, int> mp;
			for (int j = 0;j + i < s.size();j++) {
				string cmp = s.substr(j, 1) + s.substr(j + i, 1);
				if (mp.count(cmp) == 0) mp[cmp] = 1;
				else {
					cout << s << " is NOT surprising.\n";
					flag = true;
					break;
				}
			}
			if (flag == true) break;
		}
		if (flag == true) continue;
		cout << s << " is surprising.\n";
	}
}