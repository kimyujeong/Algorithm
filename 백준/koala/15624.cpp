#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
ll n;
ll dp[1000000];

ll fib(ll x) {
	if (x == 0) return 0;
	else if (x == 1) return 1;
	else if (dp[x] != -1) return dp[x];
	return dp[x] = (fib(x - 1)+fib(x - 2)) % 1000000007;

}

int main() {
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << fib(n) << endl;
}