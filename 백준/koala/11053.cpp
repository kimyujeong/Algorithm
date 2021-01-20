#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
vector<int> A;
int dp[1000];

int main() {

	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		A.push_back(k);
	}
	
	int max_num = -1;
	for (int i = 0;i < n;i++) {
		dp[i] = 1;
		for (int j = 0;j < i;j++) {
			if (A[j] < A[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		max_num = max(max_num, dp[i]);
	}

	cout << max_num << endl;
}