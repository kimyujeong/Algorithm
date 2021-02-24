#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

char arr[12][6];
bool check[12][6];
queue<pair<int, int>> q;

int move_num;
vector<pair<int, int>> v;

int x_[4] = { 0,0,1,-1 };
int y_[4] = { 1,-1,0,0 };

void bfs(int y, int x) {
	
	vector<pair<int, int>> vv; // 임시 저장 벡터
	int tmp = 0;

	q.push({ y,x });
	check[y][x] = true;
	while (!q.empty()) {
		int node_y = q.front().first;
		int node_x = q.front().second;

		tmp++; // 같은 영역의 갯수
		vv.push_back({ node_y,node_x }); // 임시 벡터에 저장하기

		q.pop();
		for (int i = 0;i < 4;i++) {
			int next_y = node_y + y_[i];
			int next_x = node_x + x_[i];
			if (next_y >= 12 || next_y < 0 || next_x >= 6 || next_x < 0) continue;
			if (check[next_y][next_x]) continue;
			if (arr[next_y][next_x] == arr[node_y][node_x]) {
				q.push({ next_y,next_x });
				check[next_y][next_x] = true;
			}
		}
	}

	if (tmp >= 4) { // 4개보다 많다면
		move_num++; // 해당 연쇄에 움직여야하는 수
		for (auto x : vv) {
			v.push_back({ x.first,x.second }); // 진짜로 이동할 벡터에 집어넣기
		}
	}
	else vv.clear(); // 아니면 버리고 넘어가기
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);

	for (int i = 0;i < 12;i++) { // 뿌요 입력
		string s;
		cin >> s;
		for (int j = 0;j < 6;j++) {
			arr[i][j] = s[j];
		}
	}

	int cnt = 0; // 연쇄 수 (결과값)

	while (1) {
		move_num = 0;
		for (int i = 0;i < 12;i++) {
			for (int j = 0;j < 6;j++) {
				if (arr[i][j] != '.' && !check[i][j]) {
					bfs(i, j);
				}
			}
		}

		if (move_num == 0) break; // 이동 변화가 없다면 끝내기

		// 아래로 떨어뜨리기
		// 떨어뜨릴 애들은 v벡터에 저장해둠 (bfs를 순회할 때)
		for (auto x : v) {
			int yy = x.first;
			int xx = x.second;
			for (int k = yy-1;k >= 0;k--) {
			arr[k + 1][xx] = arr[k][xx];
			}
			arr[0][xx] = '.';
		}
		v.clear();

		cnt++;
		memset(check, false, sizeof(check));
	}

	cout << cnt << "\n";
	
	return 0;
}
