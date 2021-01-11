#include <iostream>
#include <vector>
using namespace std;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	for (int a = 0;a <= D;a++) {
		for (int b = 0;b <= D;b++) {
			for (int c = 0;c <= D;c++) {
				if (A*a + B*b + C*c == D) {
					cout << "1\n";
					return 0;
				}
			}
		}
	}
	cout << "0\n";
	return 0;
}