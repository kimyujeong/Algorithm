#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int dp[301][2];
int n;
vector<int> v;

int main() {
	cin >> n;
	memset(dp, -1, sizeof(dp));
	v.push_back(0);
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}

	dp[0][0] = 0; dp[0][1] = 0;	
	for (int i = 1;i <= n;i++) {
		if (i == 1) {
			dp[1][0] = v[1]; dp[1][1] = v[1];
		}
		else {
			//i-1번째 계단을 밟지 않은 i번째 계단까지의 최댓값
			dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + v[i];
			
			//i-1번째 계단을 밟은 i번째 계단까지의 최댓값
			dp[i][1] = dp[i - 1][0] + v[i];
		}
	}
	cout << max(dp[n][0], dp[n][1]) << endl;
}