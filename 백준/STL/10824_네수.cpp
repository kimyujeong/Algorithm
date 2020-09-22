#include <iostream>
#include <string>
using namespace std;

int main() {

	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;

	s1 += s2;
	s3 += s4;

	cout << stoll(s1) + stoll(s3) << '\n';

	return 0;

}
