#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

bool cmp(int i, int j) {
	return i > j;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t, n, m;
	cin >> t;

	while (t--) {
		cin >> n >> m; // m: index
		queue<pair<int, int>> q;
		vector<int> v;
		int cnt = 0;

		for (int i = 0;i < n;i++) {
			int x;
			cin >> x;
			q.push({ i,x }); // {index, importance}
			v.push_back(x);
		}

		sort(v.begin(),v.end(),cmp);

		int idx = 0;
		while (1) {
			int max_num = v[idx];
			if (q.front().second < max_num) {
				q.push({ q.front().first,q.front().second });
				q.pop();
			}
			else {
				if (q.front().first == m) {
					cout << cnt + 1 << "\n";
					break;
				}
				q.pop();
				idx++;
				cnt++;
			}
		}
	}

	return 0;
}