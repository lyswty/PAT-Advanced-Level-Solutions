#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
int Find(vector<int> &s, int x) {
	if (s[x] < 0) return x;
	return s[x] = Find(s, s[x]);
}
void Union(vector<int> &s, int a, int b) {
	int fa = Find(s, a), fb = Find(s, b);
	if (fa == fb) return;
	if (s[fa] <= s[fb]) {
		s[fa] += s[fb];
		s[fb] = fa;
	}
	else {
		s[fb] += s[fa];
		s[fa] = fb;
	}
}
int main() {
	unordered_map<int, int>mp;
	int n;
	cin >> n;
	vector<int>s(n + 1, -1);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d: ", &k);
		while (k--) {
			int cur;
			cin >> cur;
			if (mp[cur]) Union(s, mp[cur], i);
			else mp[cur] = i;
		}
	}
	unordered_map<int, bool>out;
	vector<int>v;
	for (int i = 1; i <= n; i++) if (!out[Find(s, i)]) {
		out[Find(s, i)] = true;
		v.push_back(s[Find(s, i)]);
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << -v[i];
		if (i != v.size() - 1) cout << ' ';
	}
	system("pause");
	return 0;
}
