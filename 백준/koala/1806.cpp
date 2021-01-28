#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s;
vector<int> v;
vector<int> res;
int ptr_left = 0, ptr_right=0;

int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> s;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}

	int sum = v[0];
	int ans = 1;

	while (1) {

		if (sum >= s) { 
			res.push_back(ans); 
			ans--;
			ptr_left++;
			sum -= v[ptr_left-1];			
		}

		else { 
			ptr_right++;
			ans++;
			if (ptr_right == n) break;
			sum += v[ptr_right];
		}
	}

	if (res.empty()) cout << "0" << endl;
	else {
		sort(res.begin(), res.end());
		cout << res[0] << endl;
	}

}