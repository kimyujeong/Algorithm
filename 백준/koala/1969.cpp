#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	char arr[1000][50];
	int dna[4] = { 0, }; // [0]: A, [1]: C, [2]: G, [3]: T
	string s = "";
	int cnt = 0;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (arr[j][i] == 'A') dna[0]++;
			if (arr[j][i] == 'C') dna[1]++;
			if (arr[j][i] == 'G') dna[2]++;
			if (arr[j][i] == 'T') dna[3]++;
		}
		int max = -1;
		int tmp; 
		for (int j = 0;j < 4;j++) {
			if (dna[j] > max) {
				max = dna[j];
				tmp = j;
			}
			dna[j] = 0;
		}
		if (tmp == 0) {
			s += 'A';
		}
		else if (tmp == 1) {
			s += 'C';
		}
		else if (tmp == 2) {
			s += 'G';
		}
		else if (tmp == 3) {
			s += 'T';
		}
		cnt += (n - max);
	}

	for (auto x : s) {
		cout << x;
	}
	cout << endl << cnt << endl;
}