#include<iostream>
#include<cstring>
using namespace std;
bool vis[500];
int G[500][500];
int ts[500];
int n, m, v1, v2, Min = 99999999, Max = 0, nl = 0, nt = 0, cnt = 0;
void DFS(int x) {
	vis[x] = true;
	nt += ts[x];
	if (x == v2) {
		if (nl < Min) {
			Min = nl;
			Max = nt;
			cnt = 1;
		}
		else if (nl == Min) {
			cnt++;
			if (nt > Max) Max = nt;
		}
	}
	else for (int i = 0; i < n; i++)
		if (G[x][i] != -1 && nl + G[x][i] <= Min && !vis[i]) {
			nl += G[x][i];
			DFS(i);
			vis[i] = false;
			nl -= G[x][i];
			nt -= ts[i];
		}
}
int main() {
	memset(G, -1, sizeof(G));
	memset(vis, false, sizeof(vis));
	cin >> n >> m >> v1 >> v2;
	for (int i = 0; i < n; i++) cin >> ts[i];
	for (int i = 0; i < m; i++) {
		int x, y, l;
		cin >> x >> y >> l;
		G[x][y] = l;
		G[y][x] = l;
	}
	DFS(v1);
	cout << cnt << ' ' << Max;
	system("pause");
	return 0;
}
