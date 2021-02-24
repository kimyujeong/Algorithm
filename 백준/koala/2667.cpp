#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

int check[26][26];
int arr[26][26];
queue<pair<int, int>> q;
vector<int> v;

int n;

int x_[4] = { 0,0,1,-1 };
int y_[4] = { 1,-1,0,0 };

void bfs(int y, int x) {
	int tmp = 0;
	q.push({ y,x });
	check[y][x] = true;
	while (!q.empty()) {
		int node_y = q.front().first;
		int node_x = q.front().second;
		q.pop();
		tmp++;
		for (int i = 0;i < 4;i++) {
			int next_y = node_y + y_[i];
			int next_x = node_x + x_[i];
			if (next_y >= n || next_y < 0 || next_x >= n || next_x < 0) continue;
			if (check[next_y][next_x]) continue;
			if (arr[next_y][next_x]==1) {
				check[next_y][next_x] = true;
				q.push({ next_y,next_x });
			}
		}
	}
	v.push_back(tmp);
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);

	cin >> n;

	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < n;j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	int cnt = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (arr[i][j] == 1 && !check[i][j]) {
				bfs(i,j);
				cnt++;
			}
		}
	}

	sort(v.begin(), v.end());

	cout << cnt << "\n";
	for (auto x : v) cout << x << "\n";

	return 0;
}
