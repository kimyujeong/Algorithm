#include <iostream>
#include <string>
using namespace std;

int main() {
	int num;
	cin >> num;
	for (int i = 1;i <= num;i++) {
		string s = to_string(i);
		int sum = i;
		for (int j = 0;j < s.length();j++) {
			sum += stoi(s.substr(j,1));
		}
		if (sum == num) {
			cout << i << endl;
			return 0;
		}
	}
	cout << "0\n";
	return 0;
}