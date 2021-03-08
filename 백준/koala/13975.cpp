#include <iostream>
#include <queue>
#include <functional>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	for (int i = 0;i < t;i++) {

		priority_queue<ll, vector<ll>, greater<ll>> q;
		ll sum = 0;

		int k; cin >> k;
		for (int j = 0;j < k;j++) {
			ll x; cin >> x;
			q.push(x);
		}

		while (!q.empty()) {

			if (q.size() == 1) {
				break;
			}
			ll first = q.top(); q.pop();
			ll second = q.top(); q.pop();
			sum += first + second;
			q.push(first + second);
		}

		cout << sum << endl;
	}

	return 0;
}