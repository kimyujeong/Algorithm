#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, m;
	ll left = 1, right = 0, ans = 0;
	vector<ll> v;

	cin >> n >> m;
	v.resize(n);

	for (int i = 0;i < n;i++) {
		cin >> v[i];
		right = max(right, v[i]);
	}

	while (left <= right) {
		ll mid = (left + right) / 2;

		ll sum = 0;
		for (int i = 0;i < n;i++) {
			if (v[i] - mid > 0) sum += v[i] - mid;
		}

		if (sum >= m) {
			ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}

	cout << ans << "\n";

	return 0;
}