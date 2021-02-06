#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	stack<int> st;
	vector<string> result;

	int last = 1;
	bool flag = false;

	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;

		if (flag == true) continue;

		if (x >= last) {
			for (int j = last;j <= x;j++) {
				st.push(j);
				result.push_back("+");
			}
			last = x + 1;
			st.pop();
			result.push_back("-");
		}
		else {
			if (x == st.top()) {
				st.pop();
				result.push_back("-");
			}
			else {
				result.clear();
				result.push_back("NO");
				flag = true;
			}
		}
	}

	for (auto x : result) {
		cout << x << "\n";
	}

	return 0;
}