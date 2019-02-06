#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
	int n, m, level = 1, cnt = 0, max = 0, maxlevel = -1, last = 0, l = last;
	cin >> n >> m;
	queue<int>q;
	vector<vector<int>>G(n);
	for (int i = 0; i < m; i++) {
		int father, k;
		cin >> father >> k;
		while (k--) {
			int son;
			cin >> son;
			G[father - 1].push_back(son - 1);
		}
	}
	q.push(0);
	while (q.size()) {
		int cur = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < G[cur].size(); i++) {
			q.push(G[cur][i]);
			l = G[cur][i];
		}
		if (last == cur) {
			last = l;
			if (cnt > max) {
				max = cnt;
				maxlevel = level;
			}
			level++;
			cnt = 0;
		}
	}
	cout << max << ' ' << maxlevel;
	system("pause");
	return 0;
}
