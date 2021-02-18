#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, l;
	cin >> n >> l;

	map<int, pair<int, int>> mp;

	for (int i = 0;i < n;i++) {
		int d, r, g;
		cin >> d >> r >> g;
		mp[d] = { r,g };
	}

	int time = 0;
	int distance = 0;

	while (1) {
		if (distance == l) break;

		if (mp.count(distance) > 0) { // ��ȣ���� �ִٸ�

			// ��ȣ���� �ֱ�
			int cycle = mp[distance].first + mp[distance].second;

			// ��ȣ���� ������ ���ӽð� - (����ð� % �ش� ��ȣ���� �ֱ�)
			int temp = mp[distance].first - (time % cycle);

			if (temp <= 0) { // �ʷϺ�
				distance++;
				time++;
			}
			else { // ������ (�������� ���� ���ӽð�)
				time += temp;
			}
			continue;
		}

		// ��ȣ���� ���ٸ� �׳� ��������
		distance++;
		time++;
	}

	cout << time << "\n";

	return 0;
}
