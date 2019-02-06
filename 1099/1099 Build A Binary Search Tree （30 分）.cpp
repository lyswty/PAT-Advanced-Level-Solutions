#include<utility>
#include<queue>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>D, in;
vector<pair<int, int>>T;
int tmp = 0;
void inDFS(int x) {
	if (T[x].first != -1) inDFS(T[x].first);
	D[x] = in[tmp++];
	if (T[x].second != -1) inDFS(T[x].second);
}
int main() {
	int n;
	cin >> n;
	D.resize(n);
	in.resize(n);
	T.resize(n);
	for (int i = 0; i < n; i++) cin >> T[i].first >> T[i].second;
	for (int i = 0; i < n; i++) cin >> in[i];
	sort(in.begin(), in.end());
	inDFS(0);
	queue<int>q;
	q.push(0);
	cout << D[0];
	while (q.size()) {
		int cur = q.front();
		q.pop();
		if (T[cur].first != -1) {
			cout << ' ' << D[T[cur].first];
			q.push(T[cur].first);
		}
		if (T[cur].second != -1) {
			cout << ' ' << D[T[cur].second];
			q.push(T[cur].second);
		}
	}
	system("pause");
	return 0;
}
