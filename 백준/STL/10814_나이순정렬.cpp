#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
using namespace std;

struct person {
	string name;
	int age, join;
};
bool cmp(const person &a, const person &b) {
	return make_tuple(a.age,a.join) < make_tuple(b.age,b.join);
}
int main() {
	int n;
	cin >> n;
	vector<person> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i].age >> v[i].name;
		v[i].join = i + 1;
	}
	sort(v.begin(), v.end(), cmp);

	for (auto k : v) {
		cout << k.age << " " << k.name << '\n';
	}
}