#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int check[51][51];
int arr[51][51];
queue<pair<int, int>> q;
int m, n, k;

int x_[4] = { 0,0,1,-1 };
int y_[4] = { 1,-1,0,0 };

void bfs(int x, int y) { // y x
	q.push({ x,y });
	check[x][y] = true;
	while (!q.empty()) {
		int node_x = q.front().first;
		int node_y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int next_x = node_x + x_[i];
			int next_y = node_y + y_[i];
			if (next_x >= n || next_x < 0 || next_y >= m || next_y < 0) continue;
			if (check[next_x][next_y]) continue;
			if (arr[next_x][next_y]) {
				check[next_x][next_y] = true;
				q.push({ next_x,next_y });
			}
		}

	}

}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	for (int i = 0;i < t;i++) {
		
		cin >> m >> n >> k;
		int cnt = 0;
		for (int j = 0;j < k;j++) {
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int ii = 0;ii < n;ii++) { //y
			for (int j = 0;j < m;j++) { //x
				if (arr[ii][j] == 1 && !check[ii][j]) {
					bfs(ii, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";

		memset(check, false, sizeof(check));
		memset(arr, 0, sizeof(arr));
	}

	return 0;
}
