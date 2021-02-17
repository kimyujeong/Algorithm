#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

deque<int> dq;
queue<int> q;

int left(deque<int> d, int x) {
	int cnt = 0;
	while (1) {
		if (d.front() == x) {
			break;
		}
		else {
			d.push_back(d.front());
			d.pop_front();
			cnt++;
		}
	}
	return cnt;
}
int right(deque<int> d, int x) {
	int cnt = 0;
	while (1) {
		if (d.front() == x) {
			break;
		}
		else {
			d.push_front(d.back());
			d.pop_back();
			cnt++;
		}
	}
	return cnt;
}
void move(bool flag, int x) {
	if (flag) {
		for (int i = 0;i < x;i++) {
			dq.push_back(dq.front());
			dq.pop_front();
		}		
	}
	else {
		for (int i = 0;i < x;i++) {
			dq.push_front(dq.back());
			dq.pop_back();
		}
	}
	dq.pop_front();
	q.pop();
}


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
		
	for (int i = 1;i <= n;i++) {
		dq.push_back(i);
	}
	for (int i = 0;i < m;i++) {
		int x;
		cin >> x;
		q.push(x);
	}

	int res = 0;
	while (!q.empty()) {
		int num = q.front();

		deque<int> tmp(dq);
		if (left(tmp, num) <= right(tmp, num)) {
			res += left(tmp, num);
			move(true,left(tmp, num));
		}
		else {
			res += right(tmp, num);
			move(false,right(tmp, num));
		}
	}
	cout << res << endl;

	return 0;
}
