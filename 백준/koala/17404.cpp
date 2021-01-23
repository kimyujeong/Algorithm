#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1001][3];
int v[1001][3];

int main() {

	memset(dp, 0, sizeof(dp));

	int t;
	cin >> t;
	for (int i = 1;i <= t;i++) {
		for (int j = 0;j < 3;j++) {
			cin >> v[i][j];
		}
	}

	int res = 987654321;
	
	for (int k = 0;k < 3;k++) {
		dp[1][0] = res;
		dp[1][1] = res;
		dp[1][2] = res;
		dp[1][k] = v[1][k];

		for (int i = 2;i <= t;i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + v[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + v[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + v[i][2];
		}

		for (int i = 0;i < 3;i++) {
			if (i == k) continue;
			res = min(res, dp[t][i]);
		}
	}

	cout << res << endl;
}