#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

typedef long long ll;


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (q.empty()) cout << "0\n";
			else {
				cout << q.top().second << "\n";
				q.pop();
			}
		}
		else {
			if (x < 0) q.push({ -x,x });
			else q.push({ x,x });
		}
	}

	return 0;
}
