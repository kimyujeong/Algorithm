#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> ans(15);
int board[15][15];
int n, tmp = 0;

void go(int cnt) {
	if (cnt == n) {
		tmp++;
		return;
	}
	for (int i = 0;i < n;i++) {
		if (board[cnt][i] == 0) {
			for (int k = 1;k < n;k++) {
				if (cnt + k < n) board[cnt + k][i]++;
				if (cnt + k < n && i + k < n) board[cnt + k][i + k]++;
				if (cnt + k < n && i - k >= 0) board[cnt + k][i - k]++;
			}
			ans[cnt] = { cnt,i };
			go(cnt + 1);
			for (int k = 1;k < n;k++) {
				if (cnt + k < n) board[cnt + k][i]--;
				if (cnt + k < n && i + k < n) board[cnt + k][i + k]--;
				if (cnt + k < n && i - k >= 0) board[cnt + k][i - k]--;
			}
		}
	}
	return;
}

int main() {
	cin >> n;
	go(0);
	cout << tmp << "\n";
	return 0;
}