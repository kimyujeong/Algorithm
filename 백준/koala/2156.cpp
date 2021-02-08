#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

int n;
vector<int> v;
int dp[10001];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp, 0, sizeof(dp));

	cin >> n;

	v.resize(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
	}

	dp[1] = v[1];
	for (int i = 2;i <= n;i++) {
		if (i == 2) {
			dp[2] = v[1] + v[2];
			continue;
		}
		dp[i] = max(max(dp[i - 1], dp[i - 2] + v[i]), dp[i - 3] + v[i] + v[i - 1]);
	}

	cout << dp[n] << "\n";

	return 0;
}