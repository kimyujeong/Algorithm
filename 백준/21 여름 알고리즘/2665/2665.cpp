#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 987654321

int n;

int Map[51][51];
queue<pair<pair<int, int>, int>> q;
int Change[51][51];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs() {

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) Change[i][j] = MAX;

	q.push({ { 0,0 },0 });

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int changed_block = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

			if (Map[ny][nx]) { // -> Èò Ä­
				if (Change[ny][nx] <= changed_block) continue;
				Change[ny][nx] = changed_block;
				q.push({ { ny,nx }, Change[ny][nx] });
			}
			else { // -> °ËÀº Ä­
				if (Change[ny][nx] <= changed_block + 1) continue;
				Change[ny][nx] = changed_block + 1;
				q.push({ { ny,nx }, Change[ny][nx]});
			}
		}
	}

	return;

}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			Map[i][j] = s[j] - '0';
		}
	}

	bfs();

	cout << Change[n-1][n-1];

	return 0;

}