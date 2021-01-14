#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int cmp;
vector<int> v;
bool check[10];
vector<int> temp;
bool ans = false;

int change() {
	int mul = 1, ret = 0;
	for (int i = temp.size() - 1;i >= 0;i--) {
		ret += temp[i] * mul;
		mul *= 10;
	}
	return ret;
}

void back_tracking(int cnt) {
	if (cnt >= v.size()) {
		int now = change();
		if (now > cmp) {
			ans = true;
		}
		return;
	}
	for (int i = 0;i < v.size();i++) {
		if (check[i] == true) continue;
		temp.push_back(v[i]);
		check[i] = true;
		back_tracking(cnt + 1);
		if (ans == true) return;
		check[i] = false;
		temp.pop_back();
	}
}

int main() {
	int n;
	cin >> n;
	cmp = n;
	while (n != 0) {
		v.push_back(n % 10);
		n /= 10;

	}
	memset(check, false, sizeof(check));
	sort(v.begin(), v.end());
	back_tracking(0);
	if (ans == true) cout << change() << endl;
	else cout << "0" << endl;
}