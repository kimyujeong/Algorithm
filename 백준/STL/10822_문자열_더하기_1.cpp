#include <iostream>
#include <string>
using namespace std;

int main() {

	string s, str = "";
	cin >> s;
	int result = 0;

	for (char c : s) {
		if (c != ',') {
			str += c;
		}
		else {
			result += stoi(str);
			str = "";
		}
	}
	result += stoi(str);
	cout << result << '\n';

	return 0;
}