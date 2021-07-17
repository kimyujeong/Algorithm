#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

ll* arr;
ll* segmentTree;
vector<pair<int, pair<int, ll>>> command;

ll init(int node, int start, int end) {
	if (start == end) return segmentTree[node] = arr[start];

	int mid = (start + end) / 2;
	ll left_result = init(node * 2, start, mid);
	ll right_result = init(node * 2 + 1, mid + 1, end);

	return segmentTree[node] = left_result + right_result;
}

ll calc(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && right >= end) return segmentTree[node];

	int mid = (start + end) / 2;
	ll left_result = calc(node * 2, start, mid, left, right);
	ll right_result = calc(node * 2 + 1, mid + 1, end, left, right);

	return left_result + right_result;
}

ll update(int node, int start, int end, int idx, ll num) {
	if (idx < start || idx > end) return segmentTree[node]; // 범위 외의 값이면, 그대로 node의 세그먼트 트리값을 리턴
	if (start == end) return segmentTree[node] = num;

	int mid = (start + end) / 2;
	ll left_result = update(node * 2, start, mid, idx, num);
	ll right_result = update(node * 2 + 1, mid + 1, end, idx, num);

	return segmentTree[node] = left_result + right_result;
}

int main() {
	int n, m, k; cin >> n >> m >> k;

	int tree_height = (int)ceil(log2(n));
	int tree_size = (1 << (tree_height + 1));

	arr = new ll[n];
	segmentTree = new ll[tree_size];

	for (int i = 0; i < n; i++) cin >> arr[i];

	init(1, 0, n - 1);

	for (int i = 0; i < m + k; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		command.push_back({ a,{b,c} });
	}

	for (int i = 0; i < m + k; i++) {
		if (command[i].first == 1) update(1, 0, n - 1, command[i].second.first - 1, command[i].second.second);
		else cout << calc(1, 0, n - 1, command[i].second.first - 1, command[i].second.second - 1) << "\n";
	}
}