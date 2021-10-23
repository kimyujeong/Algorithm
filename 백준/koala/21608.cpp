#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> turn; // ��ȸ�ϴ� ����
vector<int> favorite[401]; // �����ϴ� ģ��
queue<pair<int, int>> max_queue;

int place[21][21] = { 0, };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int Sum = 0;

int find_favorite_friend(int num, int y, int x) {
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (place[ny][nx] == favorite[num][0] || place[ny][nx] == favorite[num][1] ||
			place[ny][nx] == favorite[num][2] || place[ny][nx] == favorite[num][3]) cnt++;
	}
	return cnt;
}

void Case2(int num) {
	// - queue�� ��ȸ�ϸ鼭 ������ ĭ �߿� ����ִ� ĭ�� ���� ���� �ڸ��� ���Ѵ�
	// (�տ������� ���� ���̱� ������, ���ٸ� �����ϰ�, ū ��쿡�� ����)

	int max_cnt = -1;
	int max_y = -1, max_x = -1;

	int cnt = 0;

	while (!max_queue.empty()) {
		int y = max_queue.front().first;
		int x = max_queue.front().second;
		cnt = 0;
		max_queue.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (place[ny][nx] == 0)  cnt++;
		}
		if (cnt > max_cnt) {
			max_cnt = cnt;
			max_y = y;
			max_x = x;
		}
	}

	place[max_y][max_x] = num;
}

void Case1() {
	// - ��ĭ�� ��ȸ�ϸ鼭, �����ϴ� �л��� ������ ĭ�� ���� ���� ���� q�� ����ִ´�
	int Max_num = 0;
	for (int i = 0; i < N*N; i++) {
		int myTurn = turn[i];

		// �ʱ�ȭ
		while (!max_queue.empty()) { max_queue.pop(); }
		Max_num = 0;

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (place[j][k] == 0) {
					int num = find_favorite_friend(myTurn, j, k);
					if (num == Max_num) {
						max_queue.push({ j,k });
					}
					else if (num > Max_num) {
						while (!max_queue.empty()) { max_queue.pop(); }
						max_queue.push({ j,k });
						Max_num = num;
					}
				}
			}
		}
		Case2(myTurn);
	}
}

void Result() {
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num = place[i][j];
			int cnt = 0; // ������ ĭ�� ���� �����ϴ� �л� ��
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
				if (place[ny][nx] == favorite[num][0] || place[ny][nx] == favorite[num][1] ||
					place[ny][nx] == favorite[num][2] || place[ny][nx] == favorite[num][3]) cnt++;
			}

			if (cnt == 1) Sum += 1;
			else if (cnt == 2) Sum += 10;
			else if (cnt == 3) Sum += 100;
			else if (cnt == 4) Sum += 1000;
		}
	}
}

int main() {

	cin >> N;
	
	for (int i = 0; i < N * N; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		turn.push_back(a);
		favorite[a].push_back(b);
		favorite[a].push_back(c);
		favorite[a].push_back(d);
		favorite[a].push_back(e);
	}

	Case1();
	Result();
	cout << Sum << endl;
}