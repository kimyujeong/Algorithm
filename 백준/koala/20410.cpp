#include <iostream>
using namespace std;

int main() {
	int m, seed, x1, x2;
	int a, c;

	cin >> m >> seed >> x1 >> x2;

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < m;j++) {
			if ((x1 == ((i*seed + j) % m)) && (x2 == ((i*x1 + j) % m))) {
				a = i;
				c = j;
			}
		}
	}
	cout << a << " " << c;
}