#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

vector<int> v;
int n, k;
bool check[100];
int ans[100];
set<int> st;

void go(int cnt) {
	if (cnt == k) {
		string s;
		for (int i = 0;i < cnt;i++) {
			s += to_string(ans[i]);
		}
		st.insert(stoi(s));
		return;
	}
	for (int i = 0;i < n;i++) {
		if (check[i] == false) {
			check[i] = true;
			ans[cnt] = v[i];
			go(cnt+1);
			check[i] = false;
		}
	}
	return;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	go(0);
	cout << st.size() << "\n";
}