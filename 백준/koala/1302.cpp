#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second < b.second;
}

int main() {
	int n;
	map<string, int> mp;
	cin >> n;
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		if (mp.count(s) == 0) mp[s] = 1;
		else mp[s]++;
	}
	vector<pair<string, int>> v(mp.begin(), mp.end());
	sort(v.begin(), v.end(), cmp);

	cout << v[v.size()-1].first << "\n";
}