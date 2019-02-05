#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>G;
vector<bool>vis;
void DFS(int x) {
	vis[x] = true;
	for (int i = 0; i < G[x].size(); i++) if (!vis[G[x][i]]) DFS(G[x][i]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	G.resize(n + 1);
	vis.resize(n + 1, false);
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}
	for (int i = 0; i < k; i++) {
		int query, need = -1;
		cin >> query;
		vis[query] = true;
		for (int x = 1; x <= n; x++) {
			if (!vis[x]) {
				need++;
				DFS(x);
			}
		}
		cout << need << endl;
		vis.assign(n + 1, false);
	}
	system("pause");
	return 0;
}
