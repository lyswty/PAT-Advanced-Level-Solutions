#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;
vector<int>in;
void DFS(const vector<pair<int, int>> &T, int x) {
	if (T[x].first != -1) DFS(T, T[x].first);
	in.push_back(x);
	if (T[x].second != -1) DFS(T, T[x].second);
}
int main() {
	int n;
	cin >> n;
	vector<bool>root(n, true);
	vector<pair<int, int>>T(n);
	for (int i = 0; i < n; i++) {
		char left, right;
		cin >> right >> left;
		if (left != '-') {
			T[i].first = left - '0';
			root[left - '0'] = false;
		}
		else T[i].first = -1;
		if (right != '-') {
			T[i].second = right - '0';
			root[right - '0'] = false;
		}
		else T[i].second = -1;
	}
	queue<int>q;
	int R = distance(root.begin(), find(root.begin(), root.end(), true));
	q.push(R);
	cout << R;
	while (q.size()) {
		int cur = q.front();
		q.pop();
		if (T[cur].first != -1) {
			cout << ' ' << T[cur].first;
			q.push(T[cur].first);
		}
		if (T[cur].second != -1) {
			cout << ' ' << T[cur].second;
			q.push(T[cur].second);
		}
	}
	cout << endl;
	DFS(T, R);
	for (int i = 0; i < n; i++) {
		cout << in[i];
		if (i != n - 1) cout << ' ';
		else cout << endl;
	}
	system("pause");
	return 0;
}
