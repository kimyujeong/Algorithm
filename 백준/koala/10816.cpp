#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n;

	vector<ll> v1, v2;
	v1.resize(n);

	for (int i = 0;i < n;i++) {
		cin >> v1[i];
	}
	sort(v1.begin(), v1.end());

	cin >> m;
	v2.resize(m);

	for (int i = 0;i < m;i++) {
		cin >> v2[i];
	}

	for (int i = 0;i < m;i++) {
		v2[i] = (upper_bound(v1.begin(), v1.end(), v2[i]) - v1.begin())
			- (lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin());
	}

	for (auto x : v2) {
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}