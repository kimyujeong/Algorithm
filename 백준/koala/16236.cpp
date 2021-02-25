#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int t = 0;
int _size = 2; // 아기 상어 크기

pair<int, int> shark_location;

int n;
int arr[21][21];
bool check[21][21];

int dist[21][21];

queue<pair<int, int>> q;
vector<pair<int, int>> v;

int x_[4] = { 0,0,1,-1 };
int y_[4] = { 1,-1,0,0 };

void bfs() { // 거리의 최솟값을 구하는 함수
	bool flag = false;
	q.push({ shark_location.first,shark_location.second });
	check[shark_location.first][shark_location.second] = true;
	dist[shark_location.first][shark_location.second] = 0;

	while (!q.empty()) {
		int node_y = q.front().first;
		int node_x = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int next_y = node_y + y_[i];
			int next_x = node_x + x_[i];
			if (next_y >= n || next_y < 0 || next_x >= n || next_x < 0) continue;
			if (check[next_y][next_x]) continue;

			if (arr[next_y][next_x] <= _size) {
				q.push({ next_y,next_x });
				check[next_y][next_x] = true;
				dist[next_y][next_x] = dist[node_y][node_x] + 1;
				if (arr[next_y][next_x] < _size && arr[next_y][next_x] !=0) {
					v.push_back({ next_y,next_x });
				}
			}
		}
	}
}

void eat(int y, int x) {
	arr[y][x] = 9;
	arr[shark_location.first][shark_location.second] = 0;
	shark_location = { y,x };

	memset(dist, 0, sizeof(dist));
	memset(check, false, sizeof(check));
	v.clear();
}

bool cmp(pair<int,int> x, pair<int,int> y) {
	if (x.first == y.first) return x.second > y.second;
	return x.first > y.first;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				shark_location = { i,j };
			}
		}
	}

	int cnt = 0;

	while (1) {

		bfs();

		// 더 이상 먹을 수 있는 물고기가 공간에 없다면 종료
		if (v.empty()) break;

		// 먹을 수 있는 물고기가 1마리면, 걔를 먹음 (빈칸/시간++)
		if (v.size() == 1) {
			cnt++;

			t += dist[v[0].first][v[0].second];

			eat(v[0].first, v[0].second);

		}

		// 먹을 수 있는 물고기가 여러마리면, 가장 위, 왼쪽 우선순위 거리 물고기 먹음
		else if (v.size() > 1) {
			cnt++;

			int min_num = 100;
			pair<int, int> temp;

			sort(v.begin(), v.end(), cmp);

			for (int i = 0;i < v.size();i++) {
				min_num =  min(min_num, dist[v[i].first][v[i].second]);
				if (dist[v[i].first][v[i].second] == min_num) {
					temp = { v[i].first,v[i].second };
				}
			}

			t += min_num;

			eat(temp.first,temp.second);
			
		}

		// 먹은 마리 수 == size 면, size++
		if (cnt == _size) {
			cnt = 0;
			_size++;
		}
	}

	cout << t << "\n";

	return 0;
}
