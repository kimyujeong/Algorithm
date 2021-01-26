#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int n, k, x;
deque <bool> check;
deque <int> dq;
int ans = 0;

void rotate() {
	dq.push_front(dq.back());
	dq.pop_back();
	check.push_front(check.back());
	check.pop_back();
}

bool cnt() {
	int count = 0;
	for (auto xx : dq) {
		if (xx == 0) count++;
	}
	if (count >= k) return true;
	else return false;
}

void simul() {

	// n-1ĭ �κ� �����ֱ�
	if (check[n - 1] == true) check[n - 1] = false;

	for (int i = n - 2;i >= 0;i--) { // ���� ���� ��Ʈ�� �ö� �κ�����
		if (check[i]) { // �κ��� �ö��ִ� ĭ
			// ����ĭ�� �κ��� ������
			// dq>=1 �̸�
			if (check[i + 1] == false && dq[i + 1] >= 1) {
				dq[i + 1]--;
				check[i] = false;
				if (i == n - 2) continue;
				check[i + 1] = true;
			}
		}
	}

	// (3��) �ö󰡴� ��ġ(0) check[0]==false�̸� �κ��ϳ� ++
	if (check[0] == false && dq[0] >= 1) {
		check[0] = true;
		dq[0]--;
	}
}

int main() {

	cin >> n >> k;
	for (int i = 0;i < 2 * n;i++) {
		cin >> x;
		dq.push_back(x);
		check.push_back(false);
	}

	while (1) {

		if (cnt()) { //4��
			cout << ans << endl;
			break;
		}
		ans++;

		rotate(); // 1��
		simul(); // 2��, 3��
	}
}