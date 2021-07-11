#include <iostream>
#include <string>
using namespace std;

char result[1000001];

bool check(int idx, string bomb) {
	string temp = "";
	for (int i = idx - bomb.length(); i < idx; i++) {
		temp += result[i];
	}

	if (temp == bomb) return true;
	else return false;
}

int main() {

	string s;
	cin >> s;

	string bomb;
	cin >> bomb;

	int ptr = 0;
	int idx = 0;
	while (ptr < s.length()) {

		result[idx++] = s[ptr];

		if (s[ptr] == bomb[bomb.length() - 1] &&
			idx >= bomb.length()) {
			// result의 뒷부분이 bomb라면
			if (check(idx, bomb)) {
				idx = idx - bomb.length();
			}
		}
		ptr++;
	}

	result[idx] = '\0'; // 결과의 끝에 NULL 문자 삽입
	idx == 0 ? printf("FRULA") : printf("%s", result);

	return 0;
}