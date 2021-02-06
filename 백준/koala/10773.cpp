#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int k;
	cin >> k;

	stack<int> st;

	for (int i = 0;i < k;i++) {
		int x;
		cin >> x;

		if (x == 0) st.pop();
		else st.push(x);
	}

	int sum = 0; int tmp = st.size();
	for (int i = 0;i < tmp;i++) {
		sum += st.top();
		st.pop();
	}

	cout << sum << "\n";

	return 0;
}