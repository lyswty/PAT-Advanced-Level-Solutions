#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<string>
using namespace std;
int main() {
	int n, root, cnt = 1, last;
	cin >> n;
	vector<pair<int, int>>T(n);
	vector<bool>isroot(n, true);
	for (int i = 0; i < n; i++) {
		string l, r;
		cin >> l >> r;
		if (l[0] == '-') T[i].first = -1;
		else {
			T[i].first = stoi(l);
			isroot[T[i].first] = false;
		}
		if (r[0] == '-') T[i].second = -1;
		else {
			T[i].second = stoi(r);
			isroot[T[i].second] = false;
		}
	}
	for (root = 0; !isroot[root]; root++);
	queue<int>q;
	q.push(root);
	last = root;
	while (q.size()) {
		int cur = q.front();
		q.pop();
		if (T[cur].first != -1) {
			cnt++;
			q.push(T[cur].first);
			last = T[cur].first;
		}
		else break;
		if (T[cur].second != -1) {
			cnt++;
			q.push(T[cur].second);
			last = T[cur].second;
		}
		else break;
	}
	if (cnt != n) cout << "NO " << root;
	else cout << "YES " << last;
	system("pause");
	return 0;
}
