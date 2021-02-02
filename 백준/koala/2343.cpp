#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v;
	v.resize(n);

	int left = 1, right = 10000 * n;
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}

	int ans = 0;

	while (left <= right) {

		int mid = (left + right) / 2;

		int sum = 0;
		int cnt = 1;
		bool flag = true;
		for (int i = 0;i < n;i++) {
			if (v[i] > mid) {
				left = mid + 1;
				flag = false;
				break;
			}
			sum += v[i];
			if (sum > mid) {
				cnt++;
				sum = v[i];
			}
		}
		
		if (flag == false) continue;
		if (cnt <= m) {
			ans = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}

	cout << ans << "\n";

	return 0;
}