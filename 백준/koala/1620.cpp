#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	map<int, string> mp_idx;
	map<string, int> mp_name;

	int n, m;
	cin >> n >> m;

	for (int i = 1;i <= n;i++) {
		string s;
		cin >> s;
		mp_idx[i] = s;
		mp_name[s] = i;
	}
	for (int i = 0;i < m;i++) {
		string s;
		cin >> s;
		if (s[0] >= 'A' && s[0] <= 'Z') {
			cout << mp_name[s] << "\n";
		}
		else {			
			int num = 0;
			for (int j = 0;j < s.size();j++) {
				num *= 10;
				num += s[j] - '0';
			}
			cout << mp_idx[num] << "\n";
		}
	}
	return 0;
}