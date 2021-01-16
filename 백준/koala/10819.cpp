#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int A[8];
bool check[8];
vector<int> v;
int ans[8];
int max_num = -10000000;

void go(int idx, int cnt) {
	if (cnt == n) {
		int sum = 0;
		for (int i = 0;i <= n - 2;i++) {
			sum += abs(ans[i] - ans[i + 1]);
		}
		max_num = max(max_num, sum);
		return;
	}
	for (int i = 0;i < n;i++) {
		if (check[i] == false) {
			check[i] = true;
			ans[cnt] = A[v[i]];
			go(i, cnt + 1);
			check[i] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> A[i];
		v.push_back(i);
	}
	go(0, 0);
	cout << max_num << endl;
}