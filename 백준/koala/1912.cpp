#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int dp[100001];
int n;
vector<int> v;
int max_num;

int main() {
	cin >> n;
	memset(dp, -1, sizeof(dp));

	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}

	dp[0] = v[0];
	max_num = v[0];
	for (int i = 1;i < n;i++) {
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		max_num = max(max_num, dp[i]);
	}

	cout << max_num << endl;
}