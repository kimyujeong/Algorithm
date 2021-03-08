#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 휴게소를 세울 간격을 이분탐색해야 함
vector<int> v;
int n, m, l;

bool go(int mid) {

	int cnt = 0;

	for (int i = 1;i < v.size();i++) {
		int dist = v[i] - v[i - 1];
		cnt += (dist / mid);

		// 나누어 떨어지는 경우: 휴게소가 겹쳐 세워지므로 1을 뺌
		if (dist % mid == 0) cnt--;
	}

	if (cnt <= m) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> l;

	v.push_back(0);
	v.push_back(l);
	for (int k = 0;k < n;k++) {
		int x; cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int left = 0, right = l;
	int result;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (go(mid)) {
			// 최소값을 구해야함
			right = mid - 1;
			result = mid;
		}
		else {
			left = mid + 1;
		}
	}
	cout << result << endl;

	return 0;
}