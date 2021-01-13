#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
char arr[10];
ll ans_max = -10e10;
ll ans_min = 10e10;
int k;
vector<int> maxi, mini;

bool go(vector<int>tmp) {
	bool flag = true;
	for (int i = 0;i < tmp.size() - 1;i++) {
		if (arr[i] == '<') {
			if (tmp[i] >= tmp[i + 1]) {
				flag = false;
				return false;
			}
		}
		else {
			if (tmp[i] <= tmp[i + 1]) {
				flag = false;
				return false;
			}
		}
	}
	ll tmp_ans = 0;
	for (int i = 0;i < tmp.size();i++) {
		tmp_ans *= 10;
		tmp_ans += tmp[i];
	}
	ans_max = max(ans_max, tmp_ans);
	ans_min = min(ans_min, tmp_ans);
	return true;
}

int main() {
	cin >> k;
	for (int i = 0;i < k;i++) cin >> arr[i];

	int ptr = 9;
	for (int i = 0;i < k + 1;i++) {
		maxi.push_back(ptr);
		ptr--;
	}
	ptr = 0;
	for (int i = 0;i < k + 1;i++) {
		mini.push_back(ptr);
		ptr++;
	}

	do {
		if (go(maxi)) break;
	} while (prev_permutation(maxi.begin(), maxi.end()));

	do {
		if (go(mini)) break;
	} while (next_permutation(mini.begin(), mini.end()));

	cout << ans_max << "\n";
	if (to_string(ans_min).size() < k + 1) cout << 0 << ans_min << endl;
	else cout << ans_min << endl;
	return 0;
}