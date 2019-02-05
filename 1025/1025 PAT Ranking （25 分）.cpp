#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
struct record {
	long long ID;
	int score, location, lrank, frank;
};
bool cmp(const record &a, const record &b) {
	if (a.score != b.score) return a.score > b.score;
	return a.ID < b.ID;
}
int main() {
	int n;
	cin >> n;
	vector<record>tlist;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		vector<record>v;
		for (int j = 0; j < k; j++) {
			record cur;
			cin >> cur.ID >> cur.score;
			cur.location = i;
			v.push_back(cur);
		}
		sort(v.begin(), v.end(), cmp);
		v[0].lrank = 1;
		for (int j = 1; j < v.size(); j++)
			if (v[j].score == v[j - 1].score) v[j].lrank = v[j - 1].lrank;
			else v[j].lrank = j + 1;
		tlist.insert(tlist.begin(), v.begin(), v.end());
	}
	sort(tlist.begin(), tlist.end(), cmp);
	cout << tlist.size() << endl << setw(13) << setfill('0') << tlist[0].ID << ' ' << 1 << ' ' << tlist[0].location << ' ' << 1 << endl;
	tlist[0].frank = 1;
	for (int i = 1; i < tlist.size(); i++) {
		if (tlist[i].score == tlist[i - 1].score) tlist[i].frank = tlist[i - 1].frank;
		else tlist[i].frank = i + 1;
		cout << setw(13) << setfill('0') << tlist[i].ID << ' ' << tlist[i].frank << ' ' << tlist[i].location << ' ' << tlist[i].lrank << endl;
	}
	system("pause");
	return 0;
}
