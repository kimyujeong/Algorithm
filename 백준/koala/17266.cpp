#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

bool calc(int x) {

	int last;

	last = 0;
	
	for (int i = 0;i < m;i++) {
		if (v[i] - x > last) return false;
		last = v[i] + x;
	}

	if (last < n) return false;
	return true;

}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	v.resize(m);

	for (int i = 0;i < m;i++) {
		cin >> v[i];
	}

	int left = 1, right = n;
	int ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (calc(mid)) {
			ans = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}

	cout << ans << "\n";

	return 0;
}