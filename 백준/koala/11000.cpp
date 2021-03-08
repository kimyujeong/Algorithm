#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	priority_queue<int,vector<int>,greater<int>> q;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0;i < n;i++) {
		int s, t;
		cin >> s >> t;
		pq.push({ s,t });
	}

	q.push(pq.top().second);
	pq.pop();

	while (!pq.empty()) {
		if (q.top() <= pq.top().first) {
			q.pop();
			q.push(pq.top().second);
			pq.pop();
		}
		else {
			q.push(pq.top().second);
			pq.pop();
		}
	}

	cout << q.size() << endl;

	return 0;
}