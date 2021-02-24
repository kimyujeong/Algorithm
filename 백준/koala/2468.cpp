#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int check[101][101];
int arr[101][101];
queue<pair<int, int>> q;

int n;

int x_[4] = { 0,0,1,-1 };
int y_[4] = { 1,-1,0,0 };

void bfs(int y, int x, int safe_max) {
	q.push({ y,x });
	check[y][x] = true;
	while (!q.empty()) {
		int node_y = q.front().first;
		int node_x = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int next_y = node_y + y_[i];
			int next_x = node_x + x_[i];
			if (next_y >= n || next_y < 0 || next_x >= n || next_x < 0) continue;
			if (check[next_y][next_x]) continue;
			if (arr[next_y][next_x] > safe_max) {
				check[next_y][next_x] = true;
				q.push({ next_y,next_x });
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);

	cin >> n;

	int min_num = 101;
	int max_num = 0;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
			min_num = min(min_num, arr[i][j]);
			max_num = max(max_num, arr[i][j]);
		}
	}

	int res = 1;
	for (int i = min_num;i <= max_num;i++) {

		int tmp = 0;
		for (int j = 0;j < n;j++) {
			for (int k = 0;k < n;k++) {
				if (!check[j][k] && arr[j][k] > i) {
					bfs(j, k, i);
					tmp++;
				}
			}
		}

		res = max(res, tmp);

		memset(check, false, sizeof(check));
	}

	std::cout << res << "\n";

	return 0;
}
