#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
struct node {
	int addr, data, next;
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int start, n, k, cnt = 0;
	cin >> start >> n >> k;
	unordered_map<int, node>mp;
	for (int i = 0; i < n; i++) {
		node cur;
		cin >> cur.addr >> cur.data >> cur.next;
		mp[cur.addr] = cur;
	}
	vector<node>v;
	while (start != -1) {
		v.push_back(mp[start]);
		cnt++;
		if (cnt == k) {
			reverse(v.end() - k, v.end());
			cnt = 0;
		}
		start = mp[start].next;
	}
	for (int i = 0; i < v.size(); i++)
		if (i != v.size() - 1) cout << setw(5) << setfill('0') << v[i].addr << ' ' << v[i].data << ' ' << setw(5) << setfill('0') << v[i + 1].addr << endl;
		else cout << setw(5) << setfill('0') << v[i].addr << ' ' << v[i].data << ' ' << -1 << endl;
	system("pause");
	return 0;
}
