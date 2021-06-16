#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<pair<int, int>> v;

	for (int i = 0;i < n;i++) {
		int s, t;
		cin >> s >> t;
		v.push_back({ t,s }); // {≥°, Ω√¿€}
	}

	sort(v.begin(), v.end());

	int ptr = 1;
	int cnt = 1;
	int end = v[0].first;

	while (ptr != v.size()) {
		if (v[ptr].second < end) {
			ptr++;
			continue;
		}
		end = v[ptr].first;
		cnt++;
		ptr++;
	}
	
	cout << cnt << endl;

	return 0;
}