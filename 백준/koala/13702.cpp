#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, k;
vector<int> v;

bool cal(int x) {
	int cnt = 0;
	for (int i = 0;i < n;i++) {
		cnt += v[i] / x;
	}
	if (cnt >= k) return true;
	else return false;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	v.resize(n);

	int left = 0, right = 0;
	int ans = 0;

	for (int i = 0;i < n;i++) {
		cin >> v[i];
		right = max(right, v[i]);
	}

	while (left <= right) {
		int mid = (left + right) / 2;

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