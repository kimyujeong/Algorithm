#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, l;
	cin >> n >> l;

	map<int, pair<int, int>> mp;

	for (int i = 0;i < n;i++) {
		int d, r, g;
		cin >> d >> r >> g;
		mp[d] = { r,g };
	}

	int time = 0;
	int distance = 0;

	while (1) {
		if (distance == l) break;

		if (mp.count(distance) > 0) { // 신호등이 있다면

			// 신호등의 주기
			int cycle = mp[distance].first + mp[distance].second;

			// 신호등의 빨간불 지속시간 - (현재시간 % 해당 신호등의 주기)
			int temp = mp[distance].first - (time % cycle);

			if (temp <= 0) { // 초록불
				distance++;
				time++;
			}
			else { // 빨간불 (빨간불의 남은 지속시간)
				time += temp;
			}
			continue;
		}

		// 신호등이 없다면 그냥 지나가기
		distance++;
		time++;
	}

	cout << time << "\n";

	return 0;
}
