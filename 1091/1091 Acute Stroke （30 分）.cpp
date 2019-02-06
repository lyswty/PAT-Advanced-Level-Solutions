#include<iostream>
#include<stack>
using namespace std;
bool G[60][1286][128];
bool vis[60][1286][128] = { false };
struct node {
	int x, y, z;
	node(){}
	node(int x, int y, int z) :x(x), y(y), z(z) {}
};
int main() {
	int n, m, l, t, total = 0;
	cin >> m >> n >> l >> t;
	for (int z = 0; z < l; z++) for (int y = 0; y < m; y++) for (int x = 0; x < n; x++) cin >> G[z][y][x];
	stack<node>s;
	for (int z = 0; z < l; z++) for (int y = 0; y < m; y++) for (int x = 0; x < n; x++) if (G[z][y][x] && !vis[z][y][x]) {
		int d = 0;
		s.push(node(x, y, z));
		vis[z][y][x] = true;
		while (s.size()) {
			node cur = s.top();
			d++;
			s.pop();
			if (cur.z - 1 >= 0 && G[cur.z - 1][cur.y][cur.x] && !vis[cur.z - 1][cur.y][cur.x]) {
				vis[cur.z - 1][cur.y][cur.x] = true;
				s.push(node(cur.x, cur.y, cur.z - 1));
			}
			if (cur.z + 1 < l&&G[cur.z + 1][cur.y][cur.x] && !vis[cur.z + 1][cur.y][cur.x]) {
				vis[cur.z + 1][cur.y][cur.x] = true;
				s.push(node(cur.x, cur.y, cur.z + 1));
			}
			if (cur.x - 1 >= 0 && G[cur.z][cur.y][cur.x - 1] && !vis[cur.z][cur.y][cur.x - 1]) {
				vis[cur.z][cur.y][cur.x - 1] = true;
				s.push(node(cur.x - 1, cur.y, cur.z));
			}
			if (cur.x + 1 < n && G[cur.z][cur.y][cur.x + 1] && !vis[cur.z][cur.y][cur.x + 1]) {
				vis[cur.z][cur.y][cur.x + 1] = true;
				s.push(node(cur.x + 1, cur.y, cur.z));
			}
			if (cur.y - 1 >= 0 && G[cur.z][cur.y - 1][cur.x] && !vis[cur.z][cur.y - 1][cur.x]) {
				vis[cur.z][cur.y - 1][cur.x] = true;
				s.push(node(cur.x, cur.y - 1, cur.z));
			}
			if (cur.y + 1 < m && G[cur.z][cur.y + 1][cur.x] && !vis[cur.z][cur.y + 1][cur.x]) {
				vis[cur.z][cur.y + 1][cur.x] = true;
				s.push(node(cur.x, cur.y + 1, cur.z));
			}
		}
		if (d >= t) total += d;
	}
	cout << total;
	system("pause");
	return 0;
}
