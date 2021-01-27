#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> v;
int ptr_left = 0, ptr_right;

int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	ptr_right = k - 1;

	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	int sum = 0;
	for (int i = ptr_left;i <= ptr_right;i++) {
		sum += v[i];
	}
	int max_num = sum;

	while (1) {

		ptr_right++;
		ptr_left++;
		if (ptr_right >= n) break;

		sum = sum - v[ptr_left-1] + v[ptr_right];
		max_num = max(max_num, sum);

	}
	cout << max_num << endl;
}