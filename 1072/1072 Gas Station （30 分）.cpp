#include<iostream>
#include<iomanip>
#include<climits>
#include<cfloat>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct station {
	int mindist, maxdist;
	double aver;
	vector<double>dist;
	station() {
		mindist = INT_MAX, maxdist = INT_MIN, aver = DBL_MAX;
	}
};
vector<station>candidates;
vector<vector<pair<int, int>>>G;
void dijkstra(int g){
	bool *vis = new bool[G.size()];
	fill(vis, vis + G.size(), false);
	int total = 0;
	candidates[g - 1].dist.resize(G.size(), INT_MAX);
	int x = G.size() - candidates.size() + g - 1;
	vis[x] = true;
	for (int i = 0; i < G[x].size(); i++) candidates[g - 1].dist[G[x][i].first] = G[x][i].second;
	while (true) {
		int min = INT_MAX, minv = -1;
		for (int i = 0; i < candidates[g - 1].dist.size(); i++) if (!vis[i] && candidates[g - 1].dist[i] < min) {
			min = candidates[g - 1].dist[i];
			minv = i;
		}
		if (minv == -1) break;
		vis[minv] = true;
		if (minv < G.size() - candidates.size()) {
			if (min < candidates[g - 1].mindist) candidates[g - 1].mindist = min;
			if (min > candidates[g - 1].maxdist) candidates[g - 1].maxdist = min;
			total += min;
		}
		for (int i = 0; i < G[minv].size(); i++) if (!vis[G[minv][i].first] && candidates[g - 1].dist[G[minv][i].first] > min + G[minv][i].second) candidates[g - 1].dist[G[minv][i].first] = min + G[minv][i].second;
	}
	candidates[g - 1].aver = (double)total / (G.size() - candidates.size());
	delete[] vis;
}
int main() {
	int n, m, k, ds, out = -1, min = INT_MIN;
	double minav;
	cin >> n >> m >> k >> ds;
	candidates.resize(m);
	G.resize(n + m);
	for (int i = 0; i < k; i++) {
		string a1, a2;
		int v1, v2, d;
		cin >> a1 >> a2 >> d;
		if (a1[0] == 'G') v1 = n + stoi(a1.substr(1)) - 1;
		else v1 = stoi(a1) - 1;
		if (a2[0] == 'G') v2 = n + stoi(a2.substr(1)) - 1;
		else v2 = stoi(a2) - 1;
		G[v1].push_back(make_pair(v2, d));
		G[v2].push_back(make_pair(v1, d));
	}
	for (int i = 1; i <= m; i++) {
		dijkstra(i);
		if (candidates[i - 1].maxdist > ds) continue;
		if (candidates[i - 1].mindist > min) {
			min = candidates[i - 1].mindist;
			minav = candidates[i - 1].aver;
			out = i;
		}
		else if (candidates[i - 1].mindist == min && candidates[i - 1].aver < minav) {
			minav = candidates[i - 1].aver;
			out = i;
		}
	}
	if (out == -1) cout << "No Solution" << endl;
	else cout << 'G' << out << endl << setprecision(1) << fixed << (double)candidates[out - 1].mindist << ' ' << setprecision(1) << fixed << candidates[out - 1].aver << endl;
	system("pause");
	return 0;
}
