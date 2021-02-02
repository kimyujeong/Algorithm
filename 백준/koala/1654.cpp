#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<ll> v;
	ll k, n;

	ll left = 1, right = 0;
	ll ans = 0;

	cin >> k >> n;

	for (int i = 0;i < k;i++) {
		ll x; cin >> x;
		v.push_back(x);
		right = max(right, x);
	}

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll cnt = 0;
		for (int i = 0;i < k;i++) {
			cnt += v[i] / mid;
		}
		if (cnt >= n) {
			ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}

	cout << ans << "\n";
}