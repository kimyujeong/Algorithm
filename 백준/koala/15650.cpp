#include <iostream>
using namespace std;

int n, m;
int check[9];
int ans[9];

void go(int idx, int cnt) {
	if (cnt==m) {
		for (int i = 0;i < m;i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = idx;i <= n;i++) {
		if (check[i] == false) {
			check[i] = true;
			ans[cnt] = i;
			go(i, cnt + 1);
			check[i] = false;
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	go(1, 0);
}