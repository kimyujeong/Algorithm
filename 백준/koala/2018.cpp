#include <iostream>
using namespace std;

int n;
int ptr_left = 1;
int ptr_right = 1;
int ans = 0;

int main() {
	cin >> n;

	while (1) {

		int sum = 0;
		for (int i = ptr_left;i <= ptr_right;i++) {
			sum += i;
		}
		if (sum == n) {
			ans++;
			ptr_right++;
		}
		else if (sum > n) {
			ptr_left++;
		}
		else if (sum < n) {
			ptr_right++;
		}

		if (ptr_right == n + 1) break;
	}

	cout << ans << endl;
}
