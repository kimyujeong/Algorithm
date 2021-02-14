#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
using namespace std;

typedef long long ll;

double cal(double x, double y, char c) {
	if (c == '+') {
		return x + y;
	}
	else if (c == '-') {
		return x - y;
	}
	else if (c == '/') {
		return x / y;
	}
	else if (c == '*') {
		return x*y;
	}
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;

	stack<double> st;

	map<char, int> mp;
	char tmp = 'A';
	for (int i = 0;i < n;i++) {
		int x; cin >> x;
		mp[tmp++] = x;
	}
	
	for (int i = 0;i < s.length();i++) {
		if (s[i] <= 'Z'&&s[i] >= 'A') st.push(mp[s[i]]);
		else {
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();
			double c = cal(b, a, s[i]);
			st.push(c);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << st.top() << endl;

	return 0;
}