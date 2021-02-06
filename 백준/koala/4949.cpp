#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

	while (1) {
		string s;
		bool check = false;
		stack<char> st;

		getline(cin, s);

		if (s == ".") break;

		for (int i = 0;i < s.length();i++) {
			if (s[i] == '(') st.push('(');
			else if (s[i] == ')') {
				if (st.empty() || st.top() != '(') check = true;
				else st.pop();
			}

			else if (s[i] == '[') st.push('[');
			else if (s[i] == ']') {
				if (st.empty() || st.top() != '[') check = true;
				else st.pop();
			}
		}

		if (!st.empty() || check == true) cout << "no\n";
		else cout << "yes\n";
	}
	return 0;
}