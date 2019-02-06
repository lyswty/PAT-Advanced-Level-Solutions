#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, k;
vector<vector<int>>G;
int BFS(int x) {
	bool *vis = new bool[n];
	fill(vis, vis + n, false);
	int cnt = 0;
	vis[x] = true;
	queue<int>q;
	q.push(x);
	int last = x, l = x, level = 0;
	while (q.size()) {
		if (level == k) break;
		int cur = q.front();
		q.pop();
		for (int i = 0; i < G[cur].size(); i++) if (!vis[G[cur][i]]) {
			vis[G[cur][i]] = true;
			q.push(G[cur][i]);
			cnt++;
			l = G[cur][i];
		}
		if (last == cur) {
			level++;
			last = l;
		}
	}
	delete[] vis;
	return cnt;
}
int main() {
	cin >> n >> k;
	G.resize(n);
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		while (m--) {
			int cur;
			cin >> cur;
			G[cur - 1].push_back(i);
		}
	}
	int p;
	cin >> p;
	while (p--) {
		int cur;
		cin >> cur;
		cout << BFS(cur - 1) << endl;
	}
	system("pause");
	return 0;
}
