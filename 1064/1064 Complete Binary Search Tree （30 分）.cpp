#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<utility>
using namespace std;
vector<int>tree, level;
void BFS() {
	queue<pair<int, int>>q;
	q.push(pair<int, int>(0, tree.size() - 1));
	while (!q.empty()) {
		int left = q.front().first, right = q.front().second;
		q.pop();
		int length = right - left + 1, sum = 0, i, ll, rl;
		for (i = 0; sum + pow(2, i) <= length; i++) sum += pow(2, i);
		if (length - sum < (int)pow(2, i - 1)) {
			rl = (sum - 1) / 2;
			ll = length - rl - 1;
		}
		else {
			ll = (sum - 1) / 2 + pow(2, i - 1);
			rl = length - ll - 1;
		}
		level.push_back(tree[left + ll]);
		if (ll) q.push(pair<int, int>(left, left + ll - 1));
		if (rl) q.push(pair<int, int>(left + ll + 1, right));
	}
}
int main() {
	int n;
	cin >> n;
	tree.resize(n);
	for (int i = 0; i < n; i++) cin >> tree[i];
	sort(tree.begin(), tree.end());
	BFS();
	for (int i = 0; i < n; i++) {
		cout << level[i];
		if (i != n - 1) cout << ' ';
	}
	system("pause");
	return 0;
}
