#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<queue>
using namespace std;
vector<vector<int>>G;
int main() {
	int n, root;
	double p, r;
	cin >> n >> p >> r;
	G.resize(n);
	for (int i = 0; i < n; i++) {
		int fa;
		cin >> fa;
		if (fa == -1) root = i;
		else G[fa].push_back(i);
	}
	int cnt = 0, last = root, l = last, layer = 0;
	queue<int>q;
	q.push(root);
	while (q.size()) {
		int cur = q.front();
		cnt++;
		q.pop();
		for (int i = 0; i < G[cur].size(); i++) {
			q.push(G[cur][i]);
			l = G[cur][i];
		}
		if (cur == last) {
			last = l;
			if (q.size()) {
				cnt = 0;
				layer++;
			}
		}
	}
	cout << setprecision(2) << fixed << p * pow(1 + r / 100, layer) << ' ' << cnt;
	system("pause");
	return 0;
}
