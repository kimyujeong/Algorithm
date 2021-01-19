#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int dp[11];
vector<int> v;

int main() {

	memset(dp, -1, sizeof(dp));

	int t;
	cin >> t;
	
	v.push_back(0);
	int max_num = -1;
	while (t--) {
		int n;
		cin >> n;
		v.push_back(n);
		max_num = max(max_num, n);
	}
	
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4;i <= max_num;i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	for (int i = 1;i < v.size();i++) {
		cout << dp[v[i]] << endl;
	}
}