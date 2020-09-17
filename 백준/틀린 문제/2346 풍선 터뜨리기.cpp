#include <iostream>
#include <list>
using namespace std;

int main() {
	list<pair<int, int>> a;
	int n;
	cin >> n;

	for (int i = 1;i <= n;i++) {
		int j;
		cin >> j;
		a.push_back({ i,j });
	}

	auto it = a.begin();
	for(int i=0;i<n-1;i++){
		cout << it->first << ' ';
		int stp = it->second;
		if (stp > 0) { //양수일 때 오른쪽으로
			auto tmp = it; //it를 저장
			++tmp;
			if (tmp == a.end()) {
				tmp = a.begin();
			}
			a.erase(it);
			it = tmp;
			for (int i = 1;i < stp;i++) {
				++it;
				if (it == a.end()){
					it = a.begin();
				}
			}
		} else if (stp < 0) { //음수일 때 왼쪽으로
			stp = -stp;
			auto tmp = it; //it를 저장
			if (tmp == a.begin()) {
				tmp = a.end();
			}
			--tmp;
			a.erase(it);
			it = tmp;
			for (int i = 1;i < stp;i++) {
				if (it == a.begin()) {
					it = a.end();
				}
				--it;
			}
		}
	}

	cout << a.front().first << '\n';

	return 0;
}