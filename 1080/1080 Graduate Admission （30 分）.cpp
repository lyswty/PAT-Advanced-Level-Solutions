#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct school {
	int quota, lastrank;
	vector<int>offer;
	school() {
		lastrank = 0;
	}
};
struct student {
	int num, GE, GI, rank;
	vector<int>apply;
	friend bool operator<(const student &a, const student &b) {
		if (a.GE + a.GI != b.GE + b.GI) return a.GE + a.GI > b.GE + b.GI;
		return a.GE > b.GE;
	}
};
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<student>stu(n);
	vector<school>sch(m);
	for (int i = 0; i < m; i++) cin >> sch[i].quota;
	for (int i = 0; i < n; i++) {
		cin >> stu[i].GE >> stu[i].GI;
		stu[i].num = i;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			stu[i].apply.push_back(x);
		}
	}
	stable_sort(stu.begin(), stu.end());
	for (int i = 0; i < stu.size(); i++) {
		if (!i || stu[i].GE + stu[i].GI != stu[i - 1].GE + stu[i - 1].GI || stu[i].GI != stu[i - 1].GI) stu[i].rank = i + 1;
		else stu[i].rank = stu[i - 1].rank;
		for (int j = 0; j < stu[i].apply.size(); j++) if (sch[stu[i].apply[j]].offer.size() < sch[stu[i].apply[j]].quota || sch[stu[i].apply[j]].lastrank == stu[i].rank) {
			sch[stu[i].apply[j]].offer.push_back(stu[i].num);
			sch[stu[i].apply[j]].lastrank = stu[i].rank;
			break;
		}
	}
	for (int i = 0; i < m; i++) {
		sort(sch[i].offer.begin(), sch[i].offer.end());
		for (int j = 0; j < sch[i].offer.size(); j++) {
			cout << sch[i].offer[j];
			if (j != sch[i].offer.size() - 1) cout << ' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
