#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	deque<pair<int, int>> q;

	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int x;
		cin >> x;
		q.push_back({ i,x });
	}

	int cnt = q.front().second;
	cout << "1 ";
	q.pop_front();
	while (!q.empty()) {
		if (cnt < 0) {
			for (int i = 0;i < -cnt - 1;i++) {
				q.push_front(q.back());
				q.pop_back();
			}
			cnt = q.back().second;
			cout << q.back().first << " ";
			q.pop_back();
		}
		else {
			for (int i = 0;i < cnt - 1;i++) {
				q.push_back(q.front());
				q.pop_front();
			}
			cnt = q.front().second;
			cout << q.front().first << " ";
			q.pop_front();
		}
	}

	return 0;
}
