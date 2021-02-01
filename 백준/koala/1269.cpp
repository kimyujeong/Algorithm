#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a, b;
	cin >> a >> b;
	map<int, int> mp;
	for (int i = 0;i < a + b;i++) {
		int x;
		cin >> x;
		if (mp.count(x) == 0) mp[x] = 1;
		else mp.erase(x);
	}
	cout << mp.size() << "\n";
}