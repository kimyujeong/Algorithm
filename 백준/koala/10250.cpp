#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	string *result = new string[t];
	for (int i = 0;i < t;i++) {
		int h, w, n;
		cin >> h >> w >> n;
		int x, y;
		x = (n / h)+1;
		y = n%h;
		if (y == 0 && h!=1) {
			x = n / h;
			y = h;
		}
		else if (y == 0 && h == 1) {
			x = n;
			y = 1;
		}
		string s;
		if (x < 10) s = "0"+to_string(x);
		else s = to_string(x);
		s = to_string(y) + s;
		result[i] = s;
	}

	for (int i = 0;i < t;i++) {
		cout << result[i] << endl;
	}
}