#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	stack<char> st1, st2;

	string s;
	cin >> s;

	for (char x : s) {
		st1.push(x);
	}

	int m;
	cin >> m;

	for (int i = 0;i < m;i++) {
		char x;
		cin >> x;

		if (x == 'L') {
			if (st1.empty()) continue;
			st2.push(st1.top());
			st1.pop();
		}
		else if (x == 'D') {
			if (st2.empty()) continue;
			st1.push(st2.top());
			st2.pop();
		}
		else if (x == 'B') {
			if (st1.empty()) continue;
			st1.pop();
		}
		else if (x == 'P') {
			char k;
			cin >> k;
			st1.push(k);
		}
	}

	int tmp = st1.size();
	for (int i = 0;i < tmp;i++) {
		st2.push(st1.top());
		st1.pop();
	}

	tmp = st2.size();
	for (int i = 0;i <tmp;i++) {
		cout << st2.top();
		st2.pop();
	}

	return 0;
}