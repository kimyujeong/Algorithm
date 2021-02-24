#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int check[9][9];
int arr[9][9];
int tmp[9][9]; // 복사할 배열
queue<pair<int, int>> q;

int n, m;
int result = 0;

int x_[4] = { 0,0,1,-1 };
int y_[4] = { 1,-1,0,0 };

void bfs(int y, int x) {
	q.push({ y,x });
	check[y][x] = true;
	while (!q.empty()) {
		int node_y = q.front().first;
		int node_x = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int next_y = node_y + y_[i];
			int next_x = node_x + x_[i];
			if (next_y >= n || next_y < 0 || next_x >= m || next_x < 0) continue;
			if (check[next_y][next_x]) continue;
			if (tmp[next_y][next_x] == 0) {
				check[next_y][next_x] = true;
				tmp[next_y][next_x] = 2;
				q.push({ next_y,next_x });
			}
		}
	}
}

void go(int cnt) {
	if (cnt == 3) {
		int res = 0;

		memcpy(tmp, arr, sizeof(tmp));

		// 바이러스 전염시키기
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (tmp[i][j] == 2 && !check[i][j]) {
					bfs(i, j);
				}
			}
		}

		// 안전 영역 갯수 세기
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (tmp[i][j] == 0) {
					res++;
				}
			}
		}

		result = max(result, res);

		memcpy(tmp, arr, sizeof(tmp));
		memset(check, false, sizeof(check));
		return;
	}

	// 벽 3개 세우기
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				go(cnt + 1);
				arr[i][j] = 0;
			}
		}
	}
	return;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);

	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> arr[i][j];
		}
	}

	go(0);

	cout << result << "\n";

	return 0;
}
