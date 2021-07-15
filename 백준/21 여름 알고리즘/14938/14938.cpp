#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 987654321

int Item[100];
int n, m, r;
vector<pair<int, int>> Map[100];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int dist[100];

int dijkstra(int start) {

	fill(dist, dist + n, MAX);

	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (int i = 0; i < Map[node].size(); i++) {
			int next = Map[node][i].first;
			int next_cost = Map[node][i].second;

			if (dist[next] > cost + next_cost) {
				dist[next] = cost + next_cost;
				pq.push({ dist[next],next });
			}

		}
	}

	int result = 0;
	for (int i = 0; i < n; i++)
		if (dist[i] <= m) result += Item[i];

	return result;
}


int main() {

	int answer = 0;

	cin >> n >> m >> r;

	for (int i = 0; i < n; i++) cin >> Item[i];

	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		Map[a - 1].push_back({ b - 1,l });
		Map[b - 1].push_back({ a - 1,l });
	}

	for (int i = 0; i < n; i++) answer = max(answer, dijkstra(i));

	cout << answer;
}