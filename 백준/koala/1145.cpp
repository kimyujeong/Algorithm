#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> v(5);
	cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];
	sort(v.begin(), v.end());
	int min = v[0];
	
	for (int i = min;;i++) {
		int cnt = 0;
		if (i%v[0] == 0) cnt++;
		if (i%v[1] == 0) cnt++;
		if (i%v[2] == 0) cnt++;
		if (i%v[3] == 0) cnt++;
		if (i%v[4] == 0) cnt++;
		
		if (cnt >= 3) {
			cout << i << endl;
			break;
		}
	}
}