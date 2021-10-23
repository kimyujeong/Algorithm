#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
bool check[20][20];
int Map[20][20];

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

queue<pair<int, int>> autoplay;

int autoplay_size = 0;
int autoplay_rainbow = 0;
int autoplay_y = -1;
int autoplay_x = -1;

int score = 0;

void bfs(int color, int first_y, int first_x) {
	int cnt = 1;
	int rainbow = 0;
	queue<pair<int, int>> q;
	queue<pair<int, int>> temp;

	check[first_y][first_x] = true;
	q.push({ first_y,first_x });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		temp.push({ y,x });
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if ((Map[ny][nx] == color || Map[ny][nx] == 0) && !check[ny][nx]) {
				q.push({ ny,nx });
				check[ny][nx] = true;
				cnt++;
				if (Map[ny][nx] == 0) rainbow++;
			}
		}
	}

	if (cnt >= 2 && cnt - rainbow >= 1 && cnt >= autoplay_size) {
		if (cnt > autoplay_size) autoplay = temp;
		else if (cnt == autoplay_size) {
			if (rainbow > autoplay_rainbow) autoplay = temp;
			else if (rainbow == autoplay_rainbow) {
				if (first_y > autoplay_y) autoplay = temp;
				else if (first_y == autoplay_y) {
					if (first_x > autoplay_x) autoplay = temp;
				}
			}
		}
		else return;
		autoplay_size = cnt;
		autoplay_rainbow = rainbow;
		autoplay_y = first_y;
		autoplay_x = first_x;
	}

	return;
}

void gravity() {

	for (int j = 0; j < N; j++) {
		int bottom = N - 1;
		for (int i = N - 1; i >= 0; i--) {
			if (Map[i][j] == -2) continue;
			else if (Map[i][j] == -1) bottom = i - 1;
			else {
				int temp = Map[i][j];
				Map[i][j] = -2;
				Map[bottom--][j] = temp;
			}
		}
	}

	return;
}

void rotation() {
	int tmp[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[N-1-j][i] = Map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Map[i][j] = tmp[i][j];
		}
	}

	return;
}

void rainbow_check() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (Map[i][j] == 0) check[i][j] = false;
	return;
}
int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
		}
	}

	while (1) {

		// 초기화
		memset(check, false, sizeof(check));
		autoplay_size = 0;
		autoplay_rainbow = 0;
		autoplay_y = -1;
		autoplay_x = -1;

		// autoplay할 블록 그룹 찾기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Map[i][j] >= 1 && !check[i][j]) {
					bfs(Map[i][j], i, j);
					rainbow_check();
				}
			}
		}

		if (autoplay_size < 2) break;

		// 블록 제거
		while (!autoplay.empty()) {
			int y = autoplay.front().first;
			int x = autoplay.front().second;
			Map[y][x] = -2;
			autoplay.pop();
		}

		// 점수 계산
		score += autoplay_size * autoplay_size;

		gravity();
		rotation();
		gravity();
	}

	cout << score;
}