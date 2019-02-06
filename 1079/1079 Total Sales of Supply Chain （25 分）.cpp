#include<iostream>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;
vector<vector<int>>G;
vector<int>cnt;
double p, r;
double BFS() {
	double total = 0.0, curprice = p;
	queue<int>q;
	q.push(0);
	int last = 0, l = last;
	while (q.size()) {
		int cur = q.front();
		q.pop();
		total += cnt[cur] * curprice;
		for (int i = 0; i < G[cur].size(); i++) {
			q.push(G[cur][i]);
			l = G[cur][i];
		}
		if (cur == last) {
			last = l;
			curprice += curprice * r / 100;
		}
	}
	return total;
}
int main() {
	int n;
	cin >> n >> p >> r;
	G.resize(n);
	cnt.resize(n, 0);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			G[i].push_back(x);
		}
		if (!k) cin >> cnt[i];
	}
	cout << setprecision(1) << fixed << BFS();
	system("pause");
	return 0;
}
