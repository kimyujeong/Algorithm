#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int picture[501][501];
bool check[501][501];
queue<pair<int, int>> q;
int max_area = 0;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int y, int x) {
	q.push({ y,x });
	check[y][x] = true;
	int area = 1;
	while (!q.empty()) {
		int node_y = q.front().first;
		int node_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = node_y + dy[i];
			int next_x = node_x + dx[i];
			if (picture[next_y][next_x] == 1 && !check[next_y][next_x]) {
				q.push({ next_y,next_x });
				check[next_y][next_x] = true;
				area++;
			}
		}
	}
	max_area = max(max_area, area);
	return;
}

int main() {
	
	int n, m;
	cin >> n >> m;

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> picture[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (picture[i][j]==1 && !check[i][j]) {
				cnt++;
				bfs(i, j);
			}
		}
	}

	cout << cnt << "\n" << max_area << "\n";

	return 0;
}