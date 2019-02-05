#include<iostream>
#include<iomanip>
#include<unordered_map>
using namespace std;
struct node {
	int addr, next;
	char data;
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	unordered_map<int, bool>vis;
	unordered_map<int, node>mp;
	int start1, start2, n, commonstart;
	cin >> start1 >> start2 >> n;
	for (int i = 0; i < n; i++) {
		int address;
		cin >> address;
		mp[address].addr = address;
		cin >> mp[address].data >> mp[address].next;
	}
	while (start1 != -1) {
		vis[start1] = true;
		start1 = mp[start1].next;
	}
	while (start2 != -1) {
		if (vis[start2]) {
			commonstart = start2;
			break;
		}
		start2 = mp[start2].next;
	}
	if (start2 == -1) cout << -1 << endl;
	else cout << setw(5) << setfill('0') << commonstart << endl;
	system("pause");
	return 0;
}
