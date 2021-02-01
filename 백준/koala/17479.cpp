#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b, c;
	string s; long long p;

	cin >> a >> b >> c;
	map<string, int> normal, special, service;
	for (int i = 0;i < a;i++) {
		cin >> s >> p;
		normal[s] = p;
	}
	for (int i = 0;i < b;i++) {
		cin >> s >> p;
		special[s] = p;
	}
	for (int i = 0;i < c;i++) {
		cin >> s;
		service[s] = 1; // for count
	}

	int n;
	long long no = 0, sp = 0, sv = 0; // ÃÑ °¡°Ý
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> s;
		if (normal.count(s) != 0) {
			no += normal[s];
		}
		else if (special.count(s) != 0) {
			sp += special[s];
		}
		else if (service.count(s) != 0) {
			sv += service[s];
		}
	}

	bool flag = true;
	if (sp != 0) {
		if (no >= 20000) flag = true;
		else flag = false;
	}
	if (flag == true && sv >= 1) {
		if (sv == 1 && no + sp >= 50000) flag = true;
		else flag = false;
	}

	if (flag == true) cout << "Okay\n";
	else cout << "No\n";
}