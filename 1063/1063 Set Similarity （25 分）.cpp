#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
double cal(const set<int> &a, const set<int> &b) {
	int sum = a.size() + b.size();
	vector<int>u(sum);
	auto it = set_union(a.begin(), a.end(), b.begin(), b.end(), u.begin());
	return (double)(sum - distance(u.begin(), it)) / distance(u.begin(), it);
}
int main() {
	int n, m;
	scanf("%d", &n);
	vector<set<int>>v(n);
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		while (k--) {
			int x;
			scanf("%d", &x);
			v[i].insert(x);
		}
	}
	scanf("%d", &m);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%.1f%%\n", 100 * cal(v[a - 1], v[b - 1]));
	}
	system("pause");
	return 0;
}
