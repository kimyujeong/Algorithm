#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int k, l;
	map<string, int> mp; // 학번, 순서
	int cnt = 1;

	cin >> k >> l;
	for (int i = 0;i < l;i++) {
		string s;
		cin >> s;
		mp[s] = cnt++;
	}

	vector<pair<string, int>> v(mp.begin(), mp.end());
	sort(v.begin(), v.end(), cmp);

	for (int i = 0;i < k;i++) {
		if (i >= v.size()) break;
		cout << v[i].first << "\n";
	}

	return 0;
}