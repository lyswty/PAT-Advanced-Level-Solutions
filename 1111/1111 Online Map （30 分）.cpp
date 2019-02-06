#include<vector>
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
vector<int>path1, path2;
struct edge {
	int time, length, vertex;
	edge() {}
	edge(int v,int l,int t):vertex(v),time(t),length(l){}
};
vector<vector<edge>>G;
int dijkstra1(int start, int end) {
	vector<int>dist(G.size(), INT_MAX);
	vector<int>time(G.size(), INT_MAX);
	vector<bool>vis(G.size(), false);
	for (int i = 0; i < G[start].size(); i++) {
		dist[G[start][i].vertex] = G[start][i].length;
		time[G[start][i].vertex] = G[start][i].time;
	}
	while (true) {
		int minv = -1, min = INT_MAX;
		for (int i = 0; i < G.size(); i++) if (dist[i] < min && !vis[i]) {
			min = dist[i];
			minv = i;
		}
		if (minv == -1) break;
		vis[minv] = true;
		for (int i = 0; i < G[minv].size(); i++)
			if (!vis[G[minv][i].vertex] && dist[G[minv][i].vertex] > dist[minv] + G[minv][i].length) {
				time[G[minv][i].vertex] = time[minv] + G[minv][i].time;
				dist[G[minv][i].vertex] = dist[minv] + G[minv][i].length;
				path1[G[minv][i].vertex] = minv;
			}
			else if (!vis[G[minv][i].vertex] && dist[G[minv][i].vertex] == dist[minv] + G[minv][i].length && time[G[minv][i].vertex] > time[minv] + G[minv][i].time) {
				time[G[minv][i].vertex] = time[minv] + G[minv][i].time;
				path1[G[minv][i].vertex] = minv;
			}
	}
	return dist[end];
}
int dijkstra2(int start, int end) {
	vector<int>time(G.size(), INT_MAX);
	vector<bool>vis(G.size(), false);
	vector<int>cnt(G.size(), INT_MAX);
	for (int i = 0; i < G[start].size(); i++) {
		cnt[G[start][i].vertex] = 1;
		time[G[start][i].vertex] = G[start][i].time;
	}
	while (true) {
		int minv = -1, min = INT_MAX;
		for (int i = 0; i < G.size(); i++) if (time[i] < min && !vis[i]) {
			min = time[i];
			minv = i;
		}
		if (minv == -1) break;
		vis[minv] = true;
		for (int i = 0; i < G[minv].size(); i++)
			if (!vis[G[minv][i].vertex] && time[G[minv][i].vertex] > time[minv] + G[minv][i].time) {
				time[G[minv][i].vertex] = time[minv] + G[minv][i].time;
				cnt[G[minv][i].vertex] = cnt[minv] + 1;
				path2[G[minv][i].vertex] = minv;
			}
			else if (!vis[G[minv][i].vertex] && time[G[minv][i].vertex] == time[minv] + G[minv][i].time && cnt[G[minv][i].vertex] > cnt[minv] + 1) {
				cnt[G[minv][i].vertex] = cnt[minv] + 1;
				path2[G[minv][i].vertex] = minv;
			}
	}
	return time[end];
}
int main() {
	int n, m, start, end;
	cin >> n >> m;
	G.resize(n);
	for (int i = 0; i < m; i++) {
		int v1, v2, one_way, length, time;
		cin >> v1 >> v2 >> one_way >> length >> time;
		G[v1].push_back(edge(v2, length, time));
		if (!one_way) G[v2].push_back(edge(v1, length, time));
	}
	cin >> start >> end;
	path1.resize(n, start);
	path2.resize(n, start);
	int distance = dijkstra1(start, end), time = dijkstra2(start, end);
	vector<int>p1, p2;
	for (int i = end; i != start; i = path1[i]) p1.push_back(i);
	for (int i = end; i != start; i = path2[i]) p2.push_back(i);
	if (p1 == p2) {
		cout << "Distance = " << distance << "; Time = " << time << ": " << start;
		for (int i = p1.size() - 1; i >= 0; i--) cout << " -> " << p1[i];
	}
	else {
		cout << "Distance = " << distance << ": " << start;
		for (int i = p1.size() - 1; i >= 0; i--) cout << " -> " << p1[i];
		cout << endl << "Time = " << time << ": " << start;
		for (int i = p2.size() - 1; i >= 0; i--) cout << " -> " << p2[i];
	}
	system("pause");
	return 0;
}
