#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
struct node {
	int addr, data, next;
	friend bool operator<(const node &a, const node &b) {
		return a.data < b.data;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, start;
	cin >> n >> start;
	unordered_map<int, node>mp;
	while (n--) {
		node cur;
		cin >> cur.addr >> cur.data >> cur.next;
		mp[cur.addr] = cur;
	}
	vector<node>v;
	while (start != -1) {
		v.push_back(mp[start]);
		start = mp[start].next;
	}
	sort(v.begin(), v.end());
	if(v.size()) cout << v.size() << ' ' << setw(5) << setfill('0') << v[0].addr << endl;
	else cout << 0 << ' ' << -1 << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << setw(5) << setfill('0') << v[i].addr << ' ' << v[i].data << ' ';
		if (i != v.size() - 1) cout << setw(5) << setfill('0') << v[i + 1].addr << endl;
		else cout << -1 << endl;
	}
	system("pause");
	return 0;
}
