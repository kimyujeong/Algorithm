#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int h, w;
	cin >> h >> w;

	vector<int> v;

	for (int i = 0;i < w;i++) {
		int x; cin >> x;
		v.push_back(x);
	}

	int res = 0;

	for (int i = 0;i < w;i++) {
		int left = 0, right = 0;

		for (int j = 0;j < i;j++) left = max(left, v[j]);
		for (int j = i + 1;j < w;j++) right = max(right, v[j]);

		res += max(0, min(left, right) - v[i]);
	}

	cout << res << "\n";

	return 0;
}