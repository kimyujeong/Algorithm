#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	deque<int> d;

	string s;
	int x, y, count=0;
	cin >> y; // 처음 입력 받는 정수
	while (count < y) {
		cin >> s;

		if (s == "push_front") {
			cin >> x;
			d.push_front(x);
		}
		else if (s == "push_back") {
			cin >> x;
			d.push_back(x);
		}
		else if (s == "pop_front") {
			if (d.empty() == true)
				cout << -1 << '\n';
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (d.empty() == true)
				cout << -1 << '\n';
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		else if (s == "size") {
			cout << d.size() << '\n';
		}
		else if (s == "empty") {
			if (d.empty() == true)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (s == "front") {
			if (d.empty() == true)
				cout << -1 << '\n';
			else
				cout << d.front() << '\n';
		}
		else if (s == "back") {
			if (d.empty() == true)
				cout << -1 << '\n';
			else
				cout << d.back() << '\n';
		}
		count++;
	}
}