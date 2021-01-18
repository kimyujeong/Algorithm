#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int dp[201][201];
int n, k;

int main() {
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));

	for (int i = 1;i <= k;i++) {
		for (int j = 0;j <= n;j++) {
			if (i == 1 || j == 0) {
				dp[j][i] = 1;
				continue;
			}
			dp[j][i] = (dp[j - 1][i] + dp[j][i - 1]) % 1000000000;
		}
	}
	cout << dp[n][k] << endl;
}