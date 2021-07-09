#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int forest[501][501];
int dp[501][501];

int max_day = 1;
int n;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dfs(int y, int x) {

	if (dp[y][x] != 0) return dp[y][x];

	dp[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];
		if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n) continue;
		if (forest[next_y][next_x] > forest[y][x]) {
			dp[y][x] = max(dp[y][x], dfs(next_y, next_x)+1);
		}
	}

	return dp[y][x];
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> forest[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			max_day = max(max_day, dfs(i, j));
		}
	}

	cout << max_day << "\n";

	return 0;
}