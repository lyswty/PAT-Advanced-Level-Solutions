#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>G;
vector<int>depth;
vector<bool>vis;
int DFS(int x) {
	vis[x] = true;
	int max = 0, cur;
	for (int i = 0; i < G[x].size(); i++)
		if (!vis[G[x][i]]) {
			cur = DFS(G[x][i]);
			if (cur + 1 > max) max = cur + 1;
		}
	return max;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	int n, comp = 1, max = 0;
	cin >> n;
	G.resize(n + 1);
	vis.resize(n + 1, false);
	depth.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}
	depth[1] = DFS(1);
	max = depth[1];
	for (int i = 2; i <= n; i++) if (!vis[i]) {
		DFS(i);
		comp++;
	}
	if (comp > 1) cout << "Error: " << comp << " components";
	else {
		for (int i = 2; i <= n; i++) {
			vis.assign(vis.size(), false);
			depth[i] = DFS(i);
			if (depth[i] > max) max = depth[i];
		}
		for (int i = 1; i <= n; i++) if (depth[i] == max) cout << i << endl;
	}
	system("pause");
	return 0;
}
