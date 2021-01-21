#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int t;
vector<int> v;
long long dp[101];

int main() {

	memset(dp, -1, sizeof(dp));
	cin >> t;


	int max_num = -1;
	for (int i = 0;i < t;i++) {
		int k;
		cin >> k;
		v.push_back(k);
		max_num = max(max_num, k);
	}


	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	for (int i = 6;i <= max_num;i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	for (int i = 0;i < t;i++) {
		cout << dp[v[i]] << endl;
	}

}