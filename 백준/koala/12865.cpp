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
int dp[101][100001]; // i��° ���Ǳ��� ����߰�, ���濡 ���� ���ǵ��� ���԰� j�� �� �ִ� ��ġ��

int main() {

	memset(dp, 0, sizeof(dp));

	cin >> n >> k;
	w = new int[n+1];
	v = new int[n+1];

	for (int i = 1;i <= n;i++) {
		cin >> w[i] >> v[i];
	}

	int ans = -1;
	for (int i = 1;i <= n;i++) { // 1~n��° ���� ���ư��� Ž��
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