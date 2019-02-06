#include<iostream>
#include<vector>
#include<queue>
#include<iomanip>
#include<cmath>
using namespace std;
int main() {
	int n, level = 0, last = 0, l = 0, min = 99999, cnt = 0;;
	double p, r;
	cin >> n >> p >> r;
	vector<vector<int>>G(n);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		while (k--) {
			int cur;
			cin >> cur;
			G[i].push_back(cur);
		}
	}
	queue<int>q;
	q.push(0);
	while (q.size()) {
		int cur = q.front();
		if (G[cur].empty())
			if (level < min) {
				min = level;
				cnt = 1;
			}
			else cnt++;
		q.pop();
		for (int i = 0; i < G[cur].size(); i++) {
			q.push(G[cur][i]);
			l = G[cur][i];
		}
		if (last == cur) {
			level++;
			last = l;
			if (level > min) break;
		}
	}
	cout << setprecision(4) << fixed << pow(r / 100 + 1, level - 1) * p << ' ' << cnt;
	system("pause");
	return 0;
}
