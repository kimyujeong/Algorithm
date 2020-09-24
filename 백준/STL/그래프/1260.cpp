#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int node) { //인접리스트 dfs
	check[node] = true;
	printf("%d ", node);
	for (int i = 0;i < a[node].size();i++) {
		int next = a[node][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}
void bfs(int start) { //인접리스트 bfs
	queue<int> q;
	memset(check, false, sizeof(check));
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		printf("%d ", node);
		for (int i = 0;i < a[node].size();i++) {
			int next = a[node][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	
	int n, m, v;
	cin >> n >> m >> v;
	
	for (int i = 0;i < m;i++) {
		int u, k;
		cin >> u >> k;
		a[u].push_back(k);
		a[k].push_back(u);
	}
	for (int i = 1;i <= n;i++) {
		sort(a[i].begin(), a[i].end());
	}
	dfs(v);
	cout << '\n';
	bfs(v);
	cout << '\n';
	return 0;
}