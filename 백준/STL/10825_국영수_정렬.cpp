#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
using namespace std;

struct person {
	string name;
	int kor, eng, mat;
};
bool cmp(const person &a, const person &b) {
	return make_tuple(-a.kor, a.eng, -a.mat, a.name) < make_tuple(-b.kor, b.eng, -b.mat, b.name);
}
int main() {
	int n;
	cin >> n;
	vector<person> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].mat;
	}
	sort(v.begin(), v.end(), cmp);

	for (auto k : v) {
		cout << k.name << '\n';
	}
	return 0;
}