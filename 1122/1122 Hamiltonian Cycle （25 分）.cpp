#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>>G;
using namespace std;
bool query(const vector<int> &a, int n) {
	if (a.size() != n + 1) return false;
	if (a[a.size() - 1] != a[0]) return false;
	bool *vis = new bool[n + 1];
	fill(vis, vis + n + 1, false);
	for (int i = 1; i < a.size(); i++) {
		if (vis[a[i]]) return false;
		vis[a[i]] = true;
		if (find(G[a[i - 1]].begin(), G[a[i - 1]].end(), a[i]) == G[a[i - 1]].end()) return false;
	}
	return true;
}
int main() {
	int n, m, q;
	cin >> n >> m;
	G.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int k;
		cin >> k;
		vector<int>cycle(k);
		for (int j = 0; j < k; j++) cin >> cycle[j];
		if (query(cycle, n)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	system("pause");
	return 0;
}
