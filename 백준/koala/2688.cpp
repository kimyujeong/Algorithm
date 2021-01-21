#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int t;
vector<int> v;
long long dp[65][10];
long long result[65];

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

	for (int i = 0;i < 10;i++) {
		dp[1][i] = 1;
	}

	result[1] = 10;
	for (int i = 2;i <= max_num;i++) {
		result[i] = 0;
		for (int j = 0;j < 10;j++) {
			dp[i][j] = 0;
			for (int k = j;k < 10;k++) {
				dp[i][j] += dp[i - 1][k];
			}
			result[i] += dp[i][j];
		}
	}

	for (int i = 0;i < t;i++) {
		cout << result[v[i]] << endl;
	}
}