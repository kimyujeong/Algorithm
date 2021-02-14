#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, k;
	cin >> n >> k;

	deque<int> dq;

	for (int i = 1;i <= n;i++) dq.push_back(i);

	cout << "<";

	int cnt = 0;
	while (!dq.empty()) {
		cnt++;
		if (cnt == k) {
			cout << dq.front();
			dq.pop_front();
			if (!dq.empty()) cout << ", ";
			cnt = 0;
		}
		else {
			dq.push_back(dq.front());
			dq.pop_front();
		}
	}
	cout << ">\n";

	return 0;
}
