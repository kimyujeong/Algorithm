#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

typedef long long ll;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	map<char, int> mp;

	for (int i = 0;i < s.length();i++) { // 알파벳 개수 세기
		if (mp.count(s[i]) == 0) {
			mp[s[i]] = 1;
		}
		else mp[s[i]]++;
	}

	int cnt = 0;
	bool check = false;
	char check_char;
	string res = "";
	for (auto x : mp) {	// 팰린드롬을 만들 수 있는지 없는지
		if (x.second % 2 == 1) {
			cnt++;
			check = true; // 홀수 문자를 포함하는 팰린드롬
			check_char = x.first;
		}
		for (int i = 0;i < x.second / 2;i++) {
			res += x.first;
		}
		if (cnt > 1) {
			cout << "I'm Sorry Hansoo\n";
			return 0;
		}
	}

	string tmp = res;
	if (check) res += check_char;
	reverse(tmp.begin(), tmp.end());
	res += tmp;

	cout << res << "\n";

	return 0;
}