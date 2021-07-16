#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int* arr;
vector<pair<int,int>> segmentTree;

pair<int, int> init(int node, int start, int end) {
	if (start == end) return segmentTree[node] = { arr[start],arr[start] };

	int mid = (start + end) / 2;
	pair<int, int> left_result = init(node * 2, start, mid);
	pair<int, int> right_result = init(node * 2 + 1, mid + 1, end);

	return segmentTree[node] = { min(left_result.first, right_result.first),max(left_result.second,right_result.second) };
}

pair<int, int> calc(int node, int start, int end, int left, int right) {
	if (right<start || left>end) return { 1000000001,1 };
	if (start >= left && end <= right) return segmentTree[node];

	int mid = (start + end) / 2;
	pair<int, int> left_result = calc(node * 2, start, mid, left, right);
	pair<int, int> right_result = calc(node * 2 + 1, mid + 1, end, left, right);

	return { min(left_result.first, right_result.first),max(left_result.second,right_result.second) };
}


int main() {

	int n, m; 
	scanf("%d %d", &n, &m);

	arr = new int[n];

	int segment_height = (int)ceil(log2(n));
	int segment_size = (1 << (segment_height + 1));

	segmentTree.resize(segment_size);

	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	init(1, 0, n - 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int c = calc(1, 0, n - 1, a - 1, b - 1).first;
		int d = calc(1, 0, n - 1, a - 1, b - 1).second;
		printf("%d %d\n", c, d);
	}
}