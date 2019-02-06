#include<iostream>
#include<unordered_set>
using namespace std;
int s[10000];
int Find(int x) {
	if (s[x] == x) return x;
	return s[x] = Find(s[x]);
}
void Union(int a, int b) {
	int fa = Find(a), fb = Find(b);
	if (fa != fb) s[fb] = fa;
}
int main() {
	int n, max = 0, q;
	cin >> n;
	unordered_set<int>fathers;
	for (int i = 0; i < 10000; i++) s[i] = i;
	for (int i = 0; i < n; i++) {
		int k, fa;
		cin >> k;
		if (k) {
			cin >> fa;
			if (fa > max) max = fa;
		}
		for (int j = 0; j < k - 1; j++) {
			int cur;
			cin >> cur;
			if (cur > max) max = cur;
			Union(fa, cur);
		}
	}
	for (int i = 1; i <= max; i++) fathers.insert(Find(i));
	cout << fathers.size() << ' ' << max << endl;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		if (Find(a) == Find(b)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	system("pause");
	return 0;
}
