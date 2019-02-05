#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;
map<string, vector<string>>G;
unordered_map<string, int>weight;
unordered_map<string, bool>vis;
int cnt = 0, mw = 0, w = 0;
string head;
void DFS(string x) {
	vis[x] = true;
	cnt++;
	w += weight[x];
	if (weight[x] > mw) {
		mw = weight[x];
		head = x;
	}
	for (int i = 0; i < G[x].size(); i++) if (!vis[G[x][i]]) DFS(G[x][i]);
}
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string s1, s2;
		int w;
		cin >> s1 >> s2 >> w;
		G[s1].push_back(s2);
		G[s2].push_back(s1);
		weight[s1] += w;
		weight[s2] += w;
	}
	vector<pair<string, int>>out;
	for (auto it = G.begin(); it != G.end(); it++)
		if (!vis[it->first]) {
			DFS(it->first);
			if (cnt > 2 && w > k * 2) out.push_back(make_pair(head, cnt));
			cnt = 0;
			mw = 0;
			w = 0;
		}
	sort(out.begin(), out.end());
	cout << out.size() << endl;
	for (int i = 0; i < out.size(); i++) cout << out[i].first << ' ' << out[i].second << endl;
	system("pause");
	return 0;
}
