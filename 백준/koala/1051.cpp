#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int arr[50][50];
int n, m;
int check[50][50];
int ans[4];

bool go(bool flag, int x) {
	if (flag == true) {
		if (ans[0] == ans[1] && 
			ans[0] == ans[2] && 
			ans[0] == ans[3] && 
			ans[1] == ans[2] && 
			ans[1] == ans[3] && 
			ans[2] == ans[3])
			return true;
		else return false;
	}
	for (int i = 0;i <= n - x;i++) {
		for (int j = 0;j <= m - x;j++) {
			if (check[i][j] == false) {
				ans[0] = arr[i][j];
				ans[1] = arr[i + x - 1][j];
				ans[2] = arr[i][j + x - 1];
				ans[3] = arr[i + x - 1][j + x - 1];
				check[i][j] = true;
				if (go(true, x)) return true;
				check[i][j] = false;
			}
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;

		for (int j = 0;j < m;j++) {
			arr[i][j] = stoi(s.substr(j, 1));
		}
	}

	int num = min(n, m);

	for (int i = num;i > 0;i--) {
		if (go(false, i)) {
			cout << i*i << endl;
			break;
		}
	}
}