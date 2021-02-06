#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;

	for (int i = 0;i < t;i++) {
		stack<char> st;
		string s;
		cin >> s;

		bool flag = true;

		for (int j = 0;j < s.length();j++) {
			if (s[j] == '(') {
				st.push('(');
			}
			else if (s[j] == ')') {
				if (st.empty()) {
					flag = false;
					break;
				}
				else {
					st.pop();
				}
			}
		}

		if (flag == false || !st.empty()) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}