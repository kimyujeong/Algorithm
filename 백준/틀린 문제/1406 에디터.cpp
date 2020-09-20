#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {

	string s;
	cin >> s;

	list<char> editor(s.begin(), s.end());
	auto cursor = editor.end();

	int n;
	cin >> n;
	while (n--) {
		char m; //¸í·É¾î
		cin >> m;

		if (m == 'L') {
			if(cursor!=editor.begin())
				cursor--;
		}
		else if (m == 'D') {
			if(cursor!=editor.end())
				cursor++;
		}
		else if (m == 'B') {
			if (cursor != editor.begin()) {
				auto temp = cursor;
				--cursor;
				editor.erase(cursor);
				cursor = temp;
			}
		}
		else if (m == 'P') {
			char x;
			cin >> x;
			editor.insert(cursor, x);
		}

	}
	
	for (char x : editor) {
		cout << x;
	}

	cout << '\n';

	return 0;

}