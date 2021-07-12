#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	string A, B;
	cin >> A >> B;

	int cnt[4001][4001] = { 0, };
	int max_num = 0;

	for (int i = 1; i <= A.length(); i++) {

		for (int j = 1; j <= B.length(); j++) {

			if (A[i - 1] == B[j - 1]) {
				cnt[i][j] = cnt[i - 1][j - 1] + 1;
				max_num = max(max_num, cnt[i][j]);
			}

			else cnt[i][j] = 0;
		}
	}

	cout << max_num;

	return 0;
}