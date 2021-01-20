#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

string s1, s2;
int dp[1001][1001];

int main() {

	memset(dp, 0, sizeof(dp));
	cin >> s1;
	cin >> s2;

	for (int i = 1;i <= s2.length();i++) {
		for (int j = 1;j <= s1.length();j++) {
			if (s2[i-1] == s1[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else if (s2[i-1] != s1[j-1]){
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	cout << dp[s2.length()][s1.length()] << endl;
}