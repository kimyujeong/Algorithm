#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int check[1001];
vector<int> v[1001];
queue<int> q;
int n, m, f;

void bfs(int first) {
	q.push(first);
	check[first] = true;
	while (!q.empty()) {
		int node = q.front();
		cout << node << " ";
		q.pop();
		for (int i = 0;i < v[node].size();i++) {
			int next = v[node][i];
			if (check[next]) continue;			
			check[next] = true;
			q.push(next);
		}
	}
	cout << "\n";
}
void dfs(int first) {
	check[first] = true;
	cout << first << " ";
	for (int i = 0;i < v[first].size();i++) {
		int next = v[first][i];
		if (check[next]) continue;
		dfs(next);
	}
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> f;

	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1;i <= n;i++) {
		sort(v[i].begin(), v[i].end());
	}
		
	dfs(f);
	cout << "\n";
	memset(check, false, sizeof(check));
	bfs(f);

	return 0;
}
