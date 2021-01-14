#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	int num = stoi(s);
	sort(s.begin(), s.end());
	int result=num;
	
	do {
		if (stoi(s) > num) {
			result = stoi(s);
			break;
		}
	} while (next_permutation(s.begin(), s.end()));
	if (result == num) cout << "0\n";
	else cout << result << endl;
}