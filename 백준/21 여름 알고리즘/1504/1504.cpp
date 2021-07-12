#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 987654321

int N, E;

vector<pair<int, int>> Graph[801];
int dist[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


int dijkstra(int start, int finish) {

	fill(dist, dist + N + 1, MAX);

	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (int i = 0; i < Graph[node].size(); i++) {
			int next = Graph[node][i].first;
			int next_cost = Graph[node][i].second;

			if (dist[next] > cost + next_cost) {
				dist[next] = cost + next_cost;
				pq.push({ dist[next],next });
			}
		}
	}

	return dist[finish] == MAX ? -1 : dist[finish];
}

int main() {

	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		Graph[a].push_back({ b,c });
		Graph[b].push_back({ a,c });
	}

	int V1, V2;
	cin >> V1 >> V2;

	int answer1, answer2;

	// 1 -> V1 -> V2 -> N
	if (dijkstra(1, V1)!=-1 && dijkstra(V1, V2) != -1 && dijkstra(V2, N) != -1) answer1 = dijkstra(1, V1) + dijkstra(V1, V2) + dijkstra(V2, N);
	else answer1 = MAX;

	// 1 -> V2 -> V1 -> N
	if (dijkstra(1, V2) != -1 && dijkstra(V2, V1) != -1 && dijkstra(V1, N) != -1 && V1!=1 && V2!=N) answer2 = dijkstra(1, V2) + dijkstra(V2, V1) + dijkstra(V1, N);
	else answer2 = MAX;

	answer1 == answer2 && answer2 == MAX ? cout << "-1" : cout << min(answer1, answer2);

	return 0;
}