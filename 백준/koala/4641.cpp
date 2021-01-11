#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	while(1){
		for (int i = 0;;i++) {
			int k;
			cin >> k;
			v.push_back(k);
			if (v[0] == -1) break;
			if (v[i] == 0) {
				int cnt = 0;
				for (int j = 0;j < i;j++) {
					vector<int>::iterator iter = find(v.begin(), v.end(), v[j]*2);
					if (iter != v.end()) {
						cnt++;
					}
				}
				cout << cnt << endl;
				break;
			}
		}
		if (v[0] == -1) break;
		v.clear();
	}
}