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

	for (int i = 0;i < s.length();i++) { // ���ĺ� ���� ����
		if (mp.count(s[i]) == 0) {
			mp[s[i]] = 1;
		}
		else mp[s[i]]++;
	}

	int cnt = 0;
	bool check = false;
	char check_char;
	string res = "";
	for (auto x : mp) {	// �Ӹ������ ���� �� �ִ��� ������
		if (x.second % 2 == 1) {
			cnt++;
			check = true; // Ȧ�� ���ڸ� �����ϴ� �Ӹ����
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