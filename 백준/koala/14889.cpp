#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
bool check[20];
int s[20][20];
int result = 200;

void go(int idx, int cnt) {

	vector<int> v1, v2;
	int v1_sum=0, v2_sum=0;

	if (cnt == n / 2) {

		for (int i = 0;i < n;i++) {
			if (check[i] == true) {
				v1.push_back(i);
			}
			else {
				v2.push_back(i);
			}
		}

		for (int i = 0;i < n / 2;i++) {
			for (int j = 0;j < n / 2;j++) {
				v1_sum += s[v1[i]][v1[j]];
				v2_sum += s[v2[i]][v2[j]];
			}
		}

		if (abs(v1_sum - v2_sum) < result) {
			result = abs(v1_sum - v2_sum);
			return;
		}

	}
	for (int i = idx;i < n;i++) {
		if (!check[i]) {
			check[i] = true;
			go(i, cnt + 1);
			check[i] = false;
		}
	}
}

int main() {

	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> s[i][j];
		}
	}

	go(0, 0);

	cout << result << endl;
}