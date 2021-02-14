#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
using namespace std;

typedef long long ll;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, p;
	cin >> n >> p;

	stack<int> st[7];

	int cnt = 0;
	for (int i = 0;i < n;i++) {
		int str, pr;
		cin >> str >> pr;
		if (st[str].empty()) {
			st[str].push(pr);
			cnt++;
		}
		else {
			if (pr > st[str].top()) {
				st[str].push(pr);
				cnt++;
			}
			else {
				while (!st[str].empty() && st[str].top() > pr) {
					st[str].pop();
					cnt++;
				}
				if (!st[str].empty() && st[str].top() != pr) {
					st[str].push(pr);
					cnt++;
				}
				else if (st[str].empty()) {
					st[str].push(pr);
					cnt++;
				}
			}
		}
	}

	cout << cnt << endl;

	return 0;
}