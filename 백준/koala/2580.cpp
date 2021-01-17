#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int arr[9][9];
vector<pair<int, int>> v; // ºó Ä­ÀÇ À§Ä¡¸¦ ÀúÀåÇÏ´Â º¤ÅÍ
int cnt = 0;
bool flag = false;

bool check(int x) {
	int num_x = v[x].first / 3;
	int num_y = v[x].second / 3;

	for (int i = 0;i < 9;i++) {
		if (arr[v[x].first][i] == arr[v[x].first][v[x].second] && i != v[x].second)
			return false;
		if (arr[i][v[x].second] == arr[v[x].first][v[x].second] && i != v[x].first)
			return false;
	}
	for (int i = num_x * 3;i < num_x * 3 + 3;i++) {
		for (int j = num_y * 3;j < num_y * 3 + 3;j++) {
			if (arr[i][j] == arr[v[x].first][v[x].second] && i != v[x].first && j != v[x].second)
				return false;
		}
	}
	return true;
}
void sudoku(int x) {
	if (x == cnt) {
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		flag = true;
		return;
	}

	for (int i = 1;i <= 9;i++) {
		arr[v[x].first][v[x].second] = i;
		if (check(x))
			sudoku(x + 1);
		if (flag) return;
	}
	arr[v[x].first][v[x].second] = 0;
	return;
}

int main() {
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				cnt++;
				v.push_back(make_pair(i, j));
			}
		}
	}
	sudoku(0);
}