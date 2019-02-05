#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
vector<vector<int>>paths;
int cur = 0, s;
vector<vector<int>>G;
vector<int>curpath, W;
vector<bool>vis;
void DFS(int x) {
	vis[x] = true;
	curpath.push_back(W[x]);
	cur += W[x];
	if (cur == s && !G[x].size()) paths.push_back(curpath);
	else for (int i = 0; i < G[x].size(); i++) if (!vis[G[x][i]] && cur + W[G[x][i]] <= s) {
		DFS(G[x][i]);
		cur -= W[G[x][i]];
		curpath.pop_back();
	}
}
int main() {
	int n, m;
	cin >> n >> m >> s;
	G.resize(n);
	W.resize(n);
	vis.resize(n);
	for (int i = 0; i < n; i++) cin >> W[i];
	while (m--) {
		int x, k;
		cin >> x >> k;
		while (k--) {
			int y;
			cin >> y;
			G[x].push_back(y);
		}
	}
	DFS(0);
	sort(paths.begin(), paths.end(), greater<vector<int>>());
	for (int i = 0; i < paths.size(); i++) for (int j = 0; j < paths[i].size(); j++) {
		cout << paths[i][j];
		if (j != paths[i].size() - 1) cout << ' ';
		else cout << endl;
	}
	system("pause");
	return 0;
}
