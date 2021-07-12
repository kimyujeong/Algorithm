#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 987654321

int main() {

	int V, E, K;
	cin >> V >> E >> K;

	vector<pair<int, int>> Graph[20001];
	int dist[20001];
	for (int i = 1; i <= V; i++) dist[i] = MAX;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		Graph[u].push_back({ v,w });
	}

	dist[K] = 0;
	pq.push({ 0,K }); // {최단거리, 방문할 노드)

	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (int i = 0; i < Graph[node].size(); i++) {
			int next_node = Graph[node][i].first;
			int next_cost = Graph[node][i].second;

			if (dist[next_node] > cost + next_cost) {
				dist[next_node] = cost + next_cost;
				pq.push({ dist[next_node],next_node });
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == MAX) cout << "INF\n";
		else cout << dist[i] << "\n";
	}


	return 0;
}