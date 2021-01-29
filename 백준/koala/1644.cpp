#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int s = 4000005;

vector<int>arr;
bool prime[s + 3];

int n;
int ptr_left = 0, ptr_right = 0;

int main() {

	cin >> n;

	// �����佺�׳׽��� ü�� 4�鸸 ������ �Ҽ� ���ϱ�
	memset(prime, true, sizeof(prime));
	prime[1] = false;
	for (int i = 1; i <= s; i++) {
		if (prime[i] == true) {
			for (int k = 2; i*k <= s; k++) {
				prime[i * k] = false;
			}
		}
	}
	// arr�� �����ϱ�
	for (int i = 1; i <= s; i++) {
		if (prime[i] == true) arr.push_back(i);
	}

	int cnt = 0;
	int sum = arr[0];
	while (1) {
		if (sum == n) {
			cnt++;
			sum -= arr[ptr_left++];
		}
		else if (sum > n) {
			sum -= arr[ptr_left++];
		}
		else if (sum < n) {
			ptr_right++;
			if (ptr_right == arr.size()) break;
			sum += arr[ptr_right];
		}
	}
	cout << cnt << endl;
}