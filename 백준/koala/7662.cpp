#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	for (int i = 0;i < t;i++) {

		int n; cin >> n;

		priority_queue<pair<int,int>> lower_q;
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> greater_q;

		bool visited[1000001] = { false, };

		for (int j = 0;j < n;j++) {

			char c; cin >> c;
			int x; cin >> x;

			if (c == 'I') {
				lower_q.push({ x,j });
				greater_q.push({ x,j });
			}

			else if (c == 'D') {

				if (x == 1) {
					while (!lower_q.empty() && visited[lower_q.top().second])
						lower_q.pop();
					if (lower_q.empty()) continue;
					visited[lower_q.top().second] = true;
					lower_q.pop();
				}

				else if (x == -1) {
					while (!greater_q.empty() && visited[greater_q.top().second])
						greater_q.pop();
					if (greater_q.empty()) continue;
					visited[greater_q.top().second] = true;
					greater_q.pop();
				}

			}
		}
		while (!lower_q.empty() && visited[lower_q.top().second])
			lower_q.pop();
		while (!greater_q.empty() && visited[greater_q.top().second])
			greater_q.pop();

		if (lower_q.empty() || greater_q.empty()) cout << "EMPTY\n";
		else cout << lower_q.top().first << " " << greater_q.top().first << "\n";
	}

	return 0;
}