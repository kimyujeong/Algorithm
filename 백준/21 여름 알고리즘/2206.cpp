#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int Map[1001][1001];
int Visited[1001][1001][2];

queue<pair<pair<int, int>, int>> q;

int n, m;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


int bfs() {

	q.push({ { 0,0 },0 });
	Visited[0][0][0] = 1; // �ִ� ���

	while (!q.empty()) {

		int node_y = q.front().first.first;
		int node_x = q.front().first.second;
		int block = q.front().second; // 0�̶�� 1�� �μ� ��ȸ�� �ִ� ��

		if (node_y == n - 1 && node_x == m - 1) return Visited[node_y][node_x][block];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = node_y + dy[i];
			int next_x = node_x + dx[i];

			if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m) continue; // ������ ����� �ʴ���

			if (Map[next_y][next_x] == 0 && !Visited[next_y][next_x][block]) { // ������ �� �ִ���
				Visited[next_y][next_x][block] = Visited[node_y][node_x][block] + 1;
				q.push({ { next_y,next_x },block });
			}

			else if (Map[next_y][next_x] == 1 && !Visited[next_y][next_x][block]) { // �����ִ���
				if (!block) { // block == 0 �̶�� -> ���� �μ� ���� ���ٸ�
					Visited[next_y][next_x][1] = Visited[node_y][node_x][block] + 1;
					q.push({ { next_y,next_x },1 });
				}

			}
		}
	}

	return -1;
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			Map[i][j] = s[j] - '0';
		}
	}

	cout << bfs();

	return 0;
}