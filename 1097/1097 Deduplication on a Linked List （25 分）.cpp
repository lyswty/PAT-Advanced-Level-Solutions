#include<iostream>
#include<unordered_map>
#include<vector>
#include<cmath>
using namespace std;
struct node {
	int addr, data, next;
};
int main() {
	int start, n;
	scanf("%d%d", &start, &n);
	unordered_map<int, node>mp;
	unordered_map<int, bool>inlist;
	vector<node>v1, v2;
	for (int i = 0; i < n; i++) {
		node cur;
		scanf("%d%d%d", &cur.addr, &cur.data, &cur.next);
		mp[cur.addr] = cur;
	}
	while (start != -1) {
		if (inlist[abs(mp[start].data)]) v2.push_back(mp[start]);
		else {
			v1.push_back(mp[start]);
			inlist[abs(mp[start].data)] = true;
		}
		start = mp[start].next;
	}
	for (int i = 0; i < v1.size(); i++) {
		if (i != v1.size() - 1) printf("%05d %d %05d\n", v1[i].addr, v1[i].data, v1[i + 1].addr);
		else printf("%05d %d -1\n", v1[i].addr, v1[i].data);
	}
	for (int i = 0; i < v2.size(); i++) {
		if (i != v2.size() - 1) printf("%05d %d %05d\n", v2[i].addr, v2[i].data, v2[i + 1].addr);
		else printf("%05d %d -1\n", v2[i].addr, v2[i].data);
	}
	system("pause");
	return 0;
}
