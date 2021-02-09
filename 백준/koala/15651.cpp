#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

int n, m;
int ans[8];

void go(int cnt) {
	if (cnt == m) {
		for (int i = 0;i < m;i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1;i <= n;i++) {
		ans[cnt] = i;
		go(cnt + 1);
	}
	return;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	go(0);

	return 0;
}