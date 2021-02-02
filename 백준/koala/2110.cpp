#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<ll> v;
	ll n, c;
	cin >> n >> c;
	v.resize(n);

	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	ll left = 1, right = v[n - 1] - v[0];
	ll ans = left;

	while (left <= right) {

		ll mid = (left + right) / 2;
		// 가장 인접한 두 공유기 사이의 최대 거리
		int cnt = 1;
		int last = v[0];
		for (int i = 1;i < n;i++) {
			if (v[i] - last >= mid) {
				cnt++;
				last = v[i];
			}
		}
		if (cnt >= c) {
			ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;

	}

	cout << ans << "\n";

	return 0;
}