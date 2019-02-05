#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int>tree[100];
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int ID, k;
		cin >> ID >> k;
		for (int i = 0; i < k; i++) {
			int child;
			cin >> child;
			tree[ID].push_back(child);
		}
	}
	int last = 1, l, cnt = 0;
	queue<int>q;
	vector<int>c;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (!tree[cur].size()) cnt++;
		for (int i = 0; i < tree[cur].size(); i++) {
			q.push(tree[cur][i]);
			l = tree[cur][i];
		}
		if (cur == last) {
			c.push_back(cnt);
			cnt = 0;
			last = l;
		}
	}
	for (int i = 0; i < c.size(); i++) {
		cout << c[i];
		if (i != c.size() - 1) cout << ' ';
	}
	system("pause");
	return 0;
}
