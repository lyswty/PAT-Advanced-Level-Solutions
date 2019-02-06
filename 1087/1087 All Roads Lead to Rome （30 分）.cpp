#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<utility>
using namespace std;
unordered_map<string, vector<pair<string, int>>>G;
unordered_map<string, int>H;
vector<string>path, curpath;
unordered_map<string, bool>vis;
int mincost = 999999999, cost = 0, maxh = 0, curh = 0, cnt = 0;
void DFS(string x) {
	vis[x] = true;
	curpath.push_back(x);
	curh += H[x];
	if (x == "ROM") {
		if (cost < mincost) {
			path = curpath;
			mincost = cost;
			maxh = curh;
			cnt = 1;
		}
		else if (cost == mincost) {
			cnt++;
			if (curh > maxh) {
				path = curpath;
				maxh = curh;
			}
			else if (curh == maxh && curpath.size() < path.size()) path = curpath;
		}
	}
	else for (int i = 0; i < G[x].size(); i++) if (!vis[G[x][i].first] && cost + G[x][i].second <= mincost) {
		cost += G[x][i].second;
		DFS(G[x][i].first);
		cost -= G[x][i].second;
		curpath.pop_back();
			curh -= H[G[x][i].first];
			vis[G[x][i].first] = false;
	}
}
int main() {
	int n, m;
	string start;
	cin >> n >> m >> start;
	H[start] = 0;
	for (int i = 0; i < n - 1; i++) {
		string cur;
		int happiness;
		cin >> cur >> happiness;
		H[cur] = happiness;
	}
	for (int i = 0; i < m; i++) {
		string v1, v2;
		int cost;
		cin >> v1 >> v2 >> cost;
		G[v1].push_back(make_pair(v2, cost));
		G[v2].push_back(make_pair(v1, cost));
	}
	DFS(start);
	cout << cnt << ' ' << mincost << ' ' << maxh << ' ' << maxh / (path.size() - 1) << endl << start;
	for (int i = 1; i < path.size(); i++) cout << "->" << path[i];
	system("pause");
	return 0;
}
