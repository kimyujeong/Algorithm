#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, m;
vector<ll> v;

bool cal(ll x) {

	int cnt = 0;
	for (int i = 0;i < n;i++) {
		if (v[i] < x) continue;
		else cnt += v[i] / x;
	}

	if (cnt >= m) return true;
	else return false;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> m >> n;
	v.resize(n);

	ll left = 1, right = 0;
	ll ans = 0;

	for (int i = 0;i < n;i++) {
		cin >> v[i];
		right = max(right, v[i]);
	}

	while (left <= right) {
		ll mid = (left + right) / 2;

		if (cal(mid)) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << ans << "\n";

	return 0;
}