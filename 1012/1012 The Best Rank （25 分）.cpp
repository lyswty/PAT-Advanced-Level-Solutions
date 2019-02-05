#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
struct student {
	int ID, C, M, E, cr, mr, er, ar, rank;
	char best;
};
bool cmpA(const student &a, const student &b) {
	return a.C + a.M + a.E > b.C + b.M + b.E;
}
bool cmpC(const student &a, const student &b) {
	return a.C > b.C;
}
bool cmpM(const student &a, const student &b) {
	return a.M > b.M;
}
bool cmpE(const student &a, const student &b) {
	return a.E > b.E;
}
int main() {
	vector<student>v;
	unordered_map<int, student>mp;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		student cur;
		cin >> cur.ID >> cur.C >> cur.M >> cur.E;
		v.push_back(cur);
	}
	sort(v.begin(), v.end(), cmpA);
	v[0].ar = 1;
	v[0].best = 'A';
	v[0].rank = 1;
	for (int i = 1; i < n; i++) {
		if (v[i].C + v[i].M + v[i].E == v[i - 1].C + v[i - 1].M + v[i - 1].E) v[i].ar = v[i - 1].ar;
		else v[i].ar = i + 1;
		v[i].rank = v[i].ar;
		v[i].best = 'A';
	}
	sort(v.begin(), v.end(), cmpC);
	v[0].cr = 1;
	if (v[0].cr < v[0].rank) {
		v[0].rank = v[0].cr;
		v[0].best = 'C';
	}
	for (int i = 1; i < n; i++) {
		if (v[i].C == v[i - 1].C) v[i].cr = v[i - 1].cr;
		else v[i].cr = i + 1;
		if (v[i].cr < v[i].rank) {
			v[i].rank = v[i].cr;
			v[i].best = 'C';
		}
	}
	sort(v.begin(), v.end(), cmpM);
	v[0].mr = 1;
	if (v[0].mr < v[0].rank) {
		v[0].rank = v[0].mr;
		v[0].best = 'M';
	}
	for (int i = 1; i < n; i++) {
		if (v[i].M == v[i - 1].M) v[i].mr = v[i - 1].mr;
		else v[i].mr = i + 1;
		if (v[i].mr < v[i].rank) {
			v[i].rank = v[i].mr;
			v[i].best = 'M';
		}
	}
	sort(v.begin(), v.end(), cmpE);
	v[0].er = 1;
	if (v[0].er < v[0].rank) {
		v[0].rank = v[0].er;
		v[0].best = 'E';
	}
	mp[v[0].ID] = v[0];
	for (int i = 1; i < n; i++) {
		if (v[i].E == v[i - 1].E) v[i].er = v[i - 1].er;
		else v[i].er = i + 1;
		if (v[i].er < v[i].rank) {
			v[i].rank = v[i].er;
			v[i].best = 'E';
		}
		mp[v[i].ID] = v[i];
	}
	for (int i = 0; i < m; i++) {
		int query;
		cin >> query;
		if (mp.find(query) == mp.end()) cout << "N/A" << endl;
		else cout << mp[query].rank << ' ' << mp[query].best << endl;
	}
	system("pause");
	return 0;
}
