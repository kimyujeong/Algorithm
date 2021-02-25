#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr[51][51];
int check[51][51];
queue<pair<int, int>> q;

int w, h;

int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };


void bfs(int y, int x) {
	q.push({ y,x });
	check[y][x] = true;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0;i < 8;i++) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny >= h || ny < 0 || nx >= w || nx < 0) continue;
			if (check[ny][nx]) continue;
			if (arr[ny][nx] == 1) {
				check[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (1) {

		int cnt = 0;

		cin >> w >> h;

		if (w == 0 && h == 0) break;

		for (int i = 0;i < h;i++) {
			for (int j = 0;j < w;j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0;i < h;i++) {
			for (int j = 0;j < w;j++) {
				if (arr[i][j] == 1 && !check[i][j]) {
					bfs(i, j);
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