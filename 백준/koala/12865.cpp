#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int n;
int k;
int *w;
int *v;
int dp[101][100001]; // i번째 물건까지 고려했고, 가방에 넣은 물건들의 무게가 j일 때 최대 가치합

int main() {

	memset(dp, 0, sizeof(dp));

	cin >> n >> k;
	w = new int[n+1];
	v = new int[n+1];

	for (int i = 1;i <= n;i++) {
		cin >> w[i] >> v[i];
	}

	int ans = -1;
	for (int i = 1;i <= n;i++) { // 1~n번째 물건 돌아가며 탐색
		for (int j = 1;j <= k;j++) {
			if (j >= w[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
			else dp[i][j] = dp[i - 1][j];
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << endl;

	return 0;
}