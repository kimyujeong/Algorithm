#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int n, k, x;
deque <bool> check;
deque <int> dq;
int ans = 0;

void rotate() {
	dq.push_front(dq.back());
	dq.pop_back();
	check.push_front(check.back());
	check.pop_back();
}

bool cnt() {
	int count = 0;
	for (auto xx : dq) {
		if (xx == 0) count++;
	}
	if (count >= k) return true;
	else return false;
}

void simul() {

	// n-1칸 로봇 내려주기
	if (check[n - 1] == true) check[n - 1] = false;

	for (int i = n - 2;i >= 0;i--) { // 가장 먼저 벨트에 올라간 로봇부터
		if (check[i]) { // 로봇이 올라가있는 칸
			// 다음칸에 로봇이 없으며
			// dq>=1 이면
			if (check[i + 1] == false && dq[i + 1] >= 1) {
				dq[i + 1]--;
				check[i] = false;
				if (i == n - 2) continue;
				check[i + 1] = true;
			}
		}
	}

	// (3번) 올라가는 위치(0) check[0]==false이면 로봇하나 ++
	if (check[0] == false && dq[0] >= 1) {
		check[0] = true;
		dq[0]--;
	}
}

int main() {

	cin >> n >> k;
	for (int i = 0;i < 2 * n;i++) {
		cin >> x;
		dq.push_back(x);
		check.push_back(false);
	}

	while (1) {

		if (cnt()) { //4번
			cout << ans << endl;
			break;
		}
		ans++;

		rotate(); // 1번
		simul(); // 2번, 3번
	}
}