#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
struct table {
	int freetime, sn;
	bool VIP;
	table() {
		freetime = 3600 * 8;
		sn = 0;
		VIP = false;
	}
};
struct customer {
	int arrive, play, wait, length;
	bool VIP;
};
bool cmp(const customer &a, const customer &b) {
	return a.arrive < b.arrive;
}
int main() {
	int n, m, k;
	cin >> n;
	vector<customer>ps;
	for (int i = 0; i < n; i++) {
		int hh, mm, ss;
		customer cur;
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &cur.length, &cur.VIP);
		cur.arrive = hh * 3600 + mm * 60 + ss;
		cur.length *= 60;
		if (cur.length > 7200) cur.length = 7200;
		ps.push_back(cur);
	}
	cin >> m >> k;
	vector<table>tables(m);
	for (int i = 0; i < k; i++) {
		int v;
		cin >> v;
		tables[v - 1].VIP = true;
	}
	sort(ps.begin(), ps.end(),cmp);
	for (int i = 0; i < n; i++) {
		int minfreetime = INT_MAX, minfree = -1;
		for (int j = 0; j < m; j++) if (tables[j].freetime < minfreetime) {
			minfreetime = tables[j].freetime;
			minfree = j;
		}
		if (minfreetime >= 21 * 3600 || ps[i].arrive >= 21 * 3600) break;
		if (ps[i].arrive < minfreetime) {
			if (tables[minfree].VIP) {
				int x;
				for (x = i; ps[x].arrive <= minfreetime && x < n; x++)
					if (ps[x].VIP) {
						ps[x].play = minfreetime;
						ps[x].wait = ps[x].play - ps[x].arrive;
						customer cur = ps[x];
						if (x != i) {
							ps.erase(ps.begin() + x);
							ps.insert(ps.begin() + i, cur);
						}
						tables[minfree].sn++;
						tables[minfree].freetime += cur.length;
						break;
					}
				if (x == n) {
					ps[i].play = minfreetime;
					ps[i].wait = ps[i].play - ps[i].arrive;
					tables[minfree].sn++;
					tables[minfree].freetime += ps[i].length;
				}
			}
			else {
				ps[i].play = minfreetime;
				ps[i].wait = ps[i].play - ps[i].arrive;
				tables[minfree].sn++;
				tables[minfree].freetime += ps[i].length;
			}
		}
		else {
			int curtable = -1;
			if (ps[i].VIP) for (int j = 0; j < m; j++) if (tables[j].VIP&&tables[j].freetime <= ps[i].arrive) {
				curtable = j;
				break;
			}
			if (curtable == -1) for (int j = 0; j < m; j++) if (tables[j].freetime <= ps[i].arrive) {
				curtable = j;
				break;
			}
			ps[i].play = ps[i].arrive;
			ps[i].wait = 0;
			tables[curtable].freetime = ps[i].play + ps[i].length;
			tables[curtable].sn++;
		}
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", ps[i].arrive / 3600, ps[i].arrive % 3600 / 60, ps[i].arrive % 60, ps[i].play / 3600, ps[i].play % 3600 / 60, ps[i].play % 60, (ps[i].wait + 30) / 60);
	}
	cout << tables[0].sn;
	for (int i = 1; i < m; i++) cout << ' ' << tables[i].sn;
	system("pause");
	return 0;
}
