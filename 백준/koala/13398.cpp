#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
vector<int> v;
int dp[100001][2]; 

int main() {
	memset(dp, -1, sizeof(dp));

	cin >> n;
	v.push_back(0);
	for (int i = 1;i <= n;i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}
		
	dp[1][0] = v[1];
	int max_num = v[1];

	for (int i = 2;i <= n;i++) {
		dp[i][0] = max(dp[i - 1][0] + v[i], v[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + v[i]);
		max_num = max(max_num, max(dp[i][0], dp[i][1]));
	}

	cout << max_num << endl;
}