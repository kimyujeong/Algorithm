#include <iostream>
#include <functional>
using namespace std;

int main() {
	
	int a, b;
	cin >> a >> b;

	function<int(int, int)> plus = [&](int a, int b) {
		return a + b;
	};

	function<int(int, int)> minus = [&](int a, int b) {
		return a - b;
	};

	function<int(int, int)> multi = [&](int a, int b) {
		return a * b;
	};

	function<int(int, int)> divi = [&](int a, int b) {
		return a / b;
	};

	function<int(int, int)> divi2 = [&](int a, int b) {
		return a % b;
	};

	cout << plus(a, b) << '\n' << minus(a, b) << '\n' << multi(a, b) << '\n' << divi(a, b) << '\n' << divi2(a, b) << '\n';

	return 0;
}