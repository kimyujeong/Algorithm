#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	int left = 1, right = k;
	int res = 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		int cnt = 0;

		for (int i = 1;i <= n;i++) {
			cnt += min(mid / i, n);
		}

		if (cnt < k) left = mid + 1;
		else {
			res = mid;
			right = mid - 1;
		}
	}

	cout << res << "\n";

	return 0;
}