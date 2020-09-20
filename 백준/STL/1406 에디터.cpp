#include <iostream>
#include <string>
using namespace std;

int main() {

	set<int> s1;
	set<int> s2 = { 1, 2, 3, 4, 5 };
	set<int> s3 = { 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3 };
	cout << "s1.size() = " << s1.size() << '\n';
	cout << "s2.size() = " << s2.size() << '\n';
	cout << "s3.size() = " << s3.size() << '\n';

	return 0;

}