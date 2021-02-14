#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

typedef long long ll;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int cnt = 0;	
	for (int i = 0;i < n;i++) {
		stack<char> st;
		string s;
		cin >> s;
		st.push(s[0]);
		for (int j = 1;j < s.length();j++) {
			if (!st.empty() && st.top() == s[j]) st.pop();
			else st.push(s[j]);
		}
		if (st.empty()) cnt++;
	}

	cout << cnt << endl;

	return 0;
}