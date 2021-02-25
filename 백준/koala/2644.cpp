#include <iostream>
#include <queue>
using namespace std;

vector<int> arr[101];
int check[101];
int dist[101];
queue<int> q;

void bfs(int x) {
	q.push(x);
	check[x] = true;
	dist[x] = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0;i < arr[node].size();i++) {
			int next = arr[node][i];
			if (check[next]) continue;
			q.push(next);
			check[next] = true;
			dist[next] = dist[node] + 1;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n;
	
	int a, b;
	cin >> a >> b;

	cin >> m;
	for (int i = 0;i < m;i++) {
		int c, d;
		cin >> c >> d;
		arr[c].push_back(d);
		arr[d].push_back(c);
	}

	bfs(b);

	if (dist[a] == 0) cout << "-1\n";
	else cout << dist[a] << "\n";

	return 0;

}