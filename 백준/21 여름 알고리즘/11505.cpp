#include <iostream>
#include <cmath>
using namespace std;

long long* segmentTree;
int* arr;

long long make_segmentTree(int node, int start, int end) {
	if (start == end) return segmentTree[node] = arr[start] % 1000000007;

	int mid = (start + end) / 2;
	long long left_result = make_segmentTree(node * 2, start, mid);
	long long right_result = make_segmentTree(node * 2 + 1, mid + 1, end);

	return segmentTree[node] = (left_result * right_result) % 1000000007;
}

long long mul(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 1;
	if (left <= start && right >= end) return segmentTree[node];

	int mid = (start + end) / 2;
	long long left_result = mul(node * 2, start, mid, left, right);
	long long right_result = mul(node * 2 + 1, mid + 1, end, left, right);

	return (left_result * right_result) % 1000000007;
}

long long update(int node, int start, int end, int index, long long num) {
	if (index < start || index > end) return segmentTree[node];
	if (start == end) return segmentTree[node] = num;

	int mid = (start + end) / 2;
	long long left_result = update(node * 2, start, mid, index, num);
	long long right_result = update(node * 2 + 1, mid + 1, end, index, num);

	return segmentTree[node] = (left_result * right_result) % 1000000007;
}

int main() {
	int n, m, k; cin >> n >> m >> k;

	int tree_height = (int)ceil(log2(n));
	int tree_size = (1 << (tree_height + 1));

	arr = new int[n];
	segmentTree = new long long[tree_size];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	make_segmentTree(1, 0, n - 1);

	for (int i = 0; i < m + k; i++) {
		int a, b, c; cin >> a >> b >> c;

		if (a == 1) {
			update(1, 0, n - 1, b - 1, c);
		}
		else if (a == 2) {
			cout << mul(1, 0, n - 1, b - 1, c - 1) % 1000000007 << "\n";
		}
	}

}