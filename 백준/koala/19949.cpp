#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

int ans[10];
vector<int> v; // 정답 배열

int result = 0;

void go(int cnt) {
	if (cnt == 10) {
		int score = 0;
		for (int i = 0;i < 10;i++) {
			if (v[i] == ans[i]) score++;
		}
		if (score >= 5) result++;
		return;
	}
	for (int i = 1;i <= 5;i++) {
		if (cnt < 2 || (cnt >= 2 && !((ans[cnt - 2] == ans[cnt - 1]) && (ans[cnt - 1] == i)))) {
			ans[cnt] = i;
			go(cnt + 1);
		}
	}
	return;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	v.resize(10);
	for (int i = 0;i < 10;i++) {
		cin >> v[i];
	}

	go(0);

	cout << result << "\n";

	return 0;
}
