#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
ll n, p, q;
map<ll, ll> mp;

ll go(ll x) {
	if (mp[x] != 0) return mp[x];
	else return mp[x] = go(x / p) + go(x / q);
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	mp[0] = 1;
	cin >> n >> p >> q;
	cout << go(n) << "\n";

	return 0;
}