#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

	int t;
	cin >> t;

	for (int i = 0;i < t;i++) {  // �׽�Ʈ���̽�

		int n;

		map<string, int> mp;
		map<int, string> mp2;
		vector<int> v;
		cin >> n;
		for (int j = 0;j < 3;j++) { // ��1����Ű, ��2����Ű
			int cnt = 1;
			for (int k = 0;k < n;k++) { // �����
				string s;
				cin >> s;
				if (j == 0) { // ��1����Ű
					mp[s] = cnt++;
				}
				else if (j == 1) { // ��2����Ű
					v.push_back(mp[s]);
				}
				else if (j == 2) { // ��ȣŰ
					mp2[v[k]] = s;
				}
			}
		}
		
		for (auto x : mp2) {
			cout << x.second << " ";
		}
		cout << "\n";
	}
}