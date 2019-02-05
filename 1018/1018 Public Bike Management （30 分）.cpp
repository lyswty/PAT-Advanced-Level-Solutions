#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;
int G[501][501], halfc, n, sp, m, bike[501], send = 0, minsend = INT_MAX, back = 0, minback = INT_MAX, dist = 0, mindist = INT_MAX;
vector<int>path, curpath;
bool vis[501];
void DFS(int x) {
	vis[x] = true;
	if (x == sp) {
		if (dist < mindist) {
			mindist = dist;
			path = curpath;
			minsend = send;
			minback = back;
		}
		else if (dist == mindist)
			if (send < minsend) {
				path = curpath;
				minsend = send;
				minback = back;
			}
			else if (send == minsend && back < minback) {
				minback = back;
				path = curpath;
			}
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && G[x][i] != -1 && dist + G[x][i] <= mindist) {
				int nowsend = send;
				int nowback = back;
				dist += G[x][i];
				curpath.push_back(i);
				if (bike[i] < halfc) {
					if (back > halfc - bike[i]) back -= halfc - bike[i];
					else {
						send += halfc - bike[i] - back;
						back = 0;
					}
				}
				else back += bike[i] - halfc;
				DFS(i);
				send = nowsend;
				back = nowback;
				curpath.pop_back();
				dist -= G[x][i];
				vis[i] = false;
			}
		}
	}
}
int main() {
	cin >> halfc >> n >> sp >> m;
	memset(G, -1, sizeof(G));
	memset(vis, false, sizeof(vis));
	bike[0] = INT_MAX;
	halfc /= 2;
	for (int i = 1; i <= n; i++) cin >> bike[i];
	for (int i = 0; i < m; i++) {
		int v1, v2, d;
		cin >> v1 >> v2 >> d;
		G[v1][v2] = d;
		G[v2][v1] = d;
	}
	DFS(0);
	cout << minsend << ' ' << 0;
	for (int i = 0; i < path.size(); i++) cout << "->" << path[i];
	cout << ' ' << minback;
	system("pause");
	return 0;
}
