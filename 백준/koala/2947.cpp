#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> v;

bool r(vector<int> v2) {
	vector<int> tmp = { 1,2,3,4,5 };

	for (int i = 0;i < 5;i++) {
		if (v2[i] != tmp[i]) return false;
	}

	return true;
}

int main() {

	for (int i = 0;i < 5;i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}

	while (1) {
		for (int i = 0;i < 4;i++) {
			if (v[i] > v[i + 1]) {
				int temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
				for (auto x : v) {
					cout << x << " ";
				}
				cout << endl;
			}
		}
		if (r(v)) break;
	}
}