#include <iostream>
#include <queue>
#include <functional>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	priority_queue<ll, vector<ll>, greater<ll>> q;

	for (int i = 0;i < n*n;i++) {
		ll x; cin >> x;
		if (q.size() == n && x > q.top()) {
			q.pop();
			q.push(x);
		}
		else if (q.size() < n) {
			q.push(x);
		}
	}

	cout << q.top() << endl;

	return 0;
}