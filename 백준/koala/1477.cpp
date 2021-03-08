#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �ްԼҸ� ���� ������ �̺�Ž���ؾ� ��
vector<int> v;
int n, m, l;

bool go(int mid) {

	int cnt = 0;

	for (int i = 1;i < v.size();i++) {
		int dist = v[i] - v[i - 1];
		cnt += (dist / mid);

		// ������ �������� ���: �ްԼҰ� ���� �������Ƿ� 1�� ��
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
			// �ּҰ��� ���ؾ���
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