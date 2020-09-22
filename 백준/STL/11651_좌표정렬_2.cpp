#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &u, const pair<int, int> &v) {
	if (u.second == v.second) return u.first < v.first;
	else return u.second < v.second;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> a(n);
	for (int i = 0; i<n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	sort(a.begin(), a.end(), cmp);
	for (auto &p : a) {
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}
