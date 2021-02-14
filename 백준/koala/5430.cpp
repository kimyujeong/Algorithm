#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

deque<string> dq;

bool RD_flag = false; // false:D true:R
bool flag = false; // error인지 아닌지

void R() {
	if (RD_flag) RD_flag = false;
	else RD_flag = true;
}

void D() {	
	if (RD_flag) dq.pop_back();
	else dq.pop_front();
}

void ptr() {
	int last = dq.size();
	cout << "[";
	for (int i = 0;i < last;i++) {
		if (RD_flag) {
			cout << dq.back();
			dq.pop_back();
		}
		else {
			cout << dq.front();
			dq.pop_front();
		}
		if (!dq.empty()) cout << ",";
	}
	cout << "]\n";
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		string p;
		cin >> p;

		int n;
		cin >> n;

		string s;
		cin >> s;
		
		string x = "";
		for (int i = 1;i < s.length();i++) { // 배열에 숫자 저장
			char tmp = s[i];
			if (tmp == ',' || tmp == ']') {
				if(x!="") dq.push_back(x);
				x = "";
				continue;
			}
			else x += tmp;
		}

		for (int i = 0;i < p.length();i++) { // R or D 명령어 수행
			if (p[i] == 'R') {
				R();
			}
			else if (p[i] == 'D') {
				if (dq.empty()) {
					cout << "error\n";
					flag = true;
					break;
				}
				D();
			}
		}

		if (!flag) ptr(); // 출력
		
		// 변수 초기화
		dq.clear();
		flag = false;
		RD_flag = false;
	}

	return 0;
}
