#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int n, m;
vector<int> v;
int tmp = 0;

bool calc(ll x) {

	int cnt = 1;
	ll sum = x;

	if (x < tmp) return false;

	for (int i = 0;i < n;i++) {
		if (sum - v[i] < 0) {
			sum = x - v[i];
			cnt++;
		}
		else {
			sum = sum - v[i];
		}
	}

	if (cnt <= m) return true;
	return false;

}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	v.resize(n);

	ll left = 1, right = 10000 * n;
	ll ans = 0;

	for (int i = 0;i < n;i++) {
		cin >> v[i];
		tmp = max(tmp, v[i]);
	}

	while (left <= right) {
		ll mid = (left + right) / 2;

		if (calc(mid)) {
			ans = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}

	cout << ans << "\n";

	return 0;
}