#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	deque<int> dq;

	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		dq.push_back(i);
	}

	int last;
	bool turn = false; // false: 버리기 true: 맨뒤로
	while (!dq.empty()) {
		last = dq.front();
		if (!turn) {
			dq.pop_front();
			turn = true;
		}
		else {
			dq.push_back(dq.front());
			dq.pop_front();
			turn = false;
		}
	}

	cout << last << "\n";

	return 0;
}
