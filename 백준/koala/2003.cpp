#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int n, m;
int _left = 0;
int _right=0;
vector<int> A;
int ans = 0;

int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		A.push_back(k);
	}

	while (1) {
		int sum = 0;
		for (int i = _left;i <= _right;i++) {
			sum += A[i];
		}
		if (sum == m) {
			ans++;
			_right++;
		}
		else if (sum > m) {
			_left++;
		}
		else if (sum < m) {
			_right++;
		}

		if (_right == n) break;
	}

	cout << ans << endl;
}