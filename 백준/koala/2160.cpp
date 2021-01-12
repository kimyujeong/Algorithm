#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	char picture[50][35];
	for (int i = 0;i < n;i++) { 
		for (int j = 0;j < 35;j++) {
			cin >> picture[i][j];
		}
	}

	vector<pair<pair<int, int>, int>> v;
	for (int i = 0;i < n;i++) {
		for (int j = i + 1;j < n;j++) {
			int cnt = 0;
			for (int k = 0;k < 35;k++) {
				if (picture[i][k] != picture[j][k]) {
					cnt++;
				}
			}
			v.push_back(make_pair(make_pair(i + 1, j + 1), cnt));
		}
	}

	int idx1;
	int idx2;
	int second = 100;
	for (auto x : v) {
		if (x.second < second) {
			second = x.second;
			idx1 = x.first.first;
			idx2 = x.first.second;
		}
	}
	cout << idx1 << " " << idx2 << endl;
}