#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

	int t;
	cin >> t;

	for (int i = 0;i < t;i++) {  // 테스트케이스

		int n;

		map<string, int> mp;
		map<int, string> mp2;
		vector<int> v;
		cin >> n;
		for (int j = 0;j < 3;j++) { // 제1공개키, 제2공개키
			int cnt = 1;
			for (int k = 0;k < n;k++) { // 문장수
				string s;
				cin >> s;
				if (j == 0) { // 제1공개키
					mp[s] = cnt++;
				}
				else if (j == 1) { // 제2공개키
					v.push_back(mp[s]);
				}
				else if (j == 2) { // 암호키
					mp2[v[k]] = s;
				}
			}
		}
		
		for (auto x : mp2) {
			cout << x.second << " ";
		}
		cout << "\n";
	}
}