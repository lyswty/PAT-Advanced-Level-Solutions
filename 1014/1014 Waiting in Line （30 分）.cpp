#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;
struct customer {
	int length, servetime;
};
int main() {
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	queue<int> *w = new queue<int>[n];
	customer *cs = new customer[k];
	for (int i = 0; i < k; i++) {
		cin >> cs[i].length;
		if (i < n) {
			cs[i].servetime = 8 * 60;
			w[i].push(i);
		}
		else if (i < n * m) {
			cs[i].servetime = cs[w[i % n].back()].length + cs[w[i % n].back()].servetime;
			w[i % n].push(i);
		}
		else {
			int min = -1, mintime = 999999999;
			for (int j = 0; j < n; j++)
				if (cs[w[j].front()].servetime + cs[w[j].front()].length < mintime) {
					mintime = cs[w[j].front()].servetime + cs[w[j].front()].length;
					min = j;
				}
			w[min].pop();
			cs[i].servetime = cs[w[min].back()].servetime + cs[w[min].back()].length;
			w[min].push(i);
		}
	}
	for (int i = 0; i < q; i++) {
		int query;
		cin >> query;
		if (cs[query - 1].servetime >= 17 * 60) cout << "Sorry" << endl;
		else {
			int hh = (cs[query - 1].servetime + cs[query - 1].length) / 60, mm = (cs[query - 1].servetime + cs[query - 1].length) % 60;
			cout << setw(2) << setfill('0') << hh << ':' << setw(2) << setfill('0') << mm << endl;
		}
	}
	system("pause");
	return 0;
}
