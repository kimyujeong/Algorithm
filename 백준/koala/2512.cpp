#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
vector<int> v;
ll m;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n);

	int left=1, right = 0;

	for (int i = 0;i < n;i++) {
		cin >> v[i];
		right = max(right, v[i]);
	}

	cin >> m;

	int ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2;

		int sum = 0;
		for (int i = 0;i < n;i++) {
			sum += min(mid, v[i]);
		}

		if (sum <= m) {
			ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}

	cout << ans << "\n";

	return 0;
}