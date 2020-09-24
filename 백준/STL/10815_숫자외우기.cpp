#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> v1(n);

	for (int i = 0;i < n;i++) {
		scanf("%d", &v1[i]);
	}

	sort(v1.begin(), v1.end());

	int m;
	scanf("%d", &m);

	for (int i = 0;i < m;i++) {
		int k;
		scanf("%d", &k);
		printf("%d ", binary_search(v1.begin(), v1.end(), k));
	}
	printf("\n");

	return 0;
}