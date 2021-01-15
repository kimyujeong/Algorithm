#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s;
vector<int> v;
int check[20];
int ans[20];
int result = 0;

void go(int idx, int cnt, int x) {
	if (cnt == x) {
		int sum = 0;
		for (int i = 0;i < x;i++) {
			sum += ans[i];
		}
		if (sum == s) result++;
	}
	for (int i = idx;i < n;i++) {
		if (check[i] == false) {
			check[i] = true;
			ans[cnt] = v[i];
			go(i, cnt + 1, x);
			check[i] = false;
		}
	}
}

int main() {
	cin >> n >> s;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	for (int i = 1;i <= n;i++) {
		go(0, 0, i);
	}
	cout << result << endl;
}