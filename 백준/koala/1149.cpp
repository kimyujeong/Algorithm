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
	for (int i =1;i <= t;i++) {
		for (int j = 0;j < 3;j++) {
			cin >> v[i][j];
		}
	}
		
	for (int i = 1;i <= t;i++) {
		for (int j = 0;j < 3;j++) {
			if (i == 1) {
				dp[i][j] = v[i][j];
				continue;
			}

			if (j == 0) {
				dp[i][0] = min(v[i][0] + dp[i - 1][1], v[i][0] + dp[i-1][2]);
			}
			else if (j == 1) {
				dp[i][1] = min(v[i][1] + dp[i - 1][0], v[i][1] + dp[i-1][2]);
			}
			else if (j == 2) {
				dp[i][2] = min(v[i][2] + dp[i - 1][0], v[i][2] + dp[i-1][1]);
			}
		}
	}

	cout << min(dp[t][0], min(dp[t][1], dp[t][2])) << endl;
}