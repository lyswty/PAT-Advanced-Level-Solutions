#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iomanip>
using namespace std;
struct Data {
	int father, sets;
	double area;
	Data() {
		sets = 0;
		area = 0.0;
		father = -1;
	}
};
unordered_map<int, Data>s;
int Find(int x) {
	if (s[x].father < 0) return x;
	return s[x].father = Find(s[x].father);
}
void Union(int a, int b) {
	int fa = Find(a), fb = Find(b);
	if (fa < fb) {
		s[fa].father += s[fb].father;
		s[fa].sets += s[fb].sets;
		s[fa].area += s[fb].area;
		s[fb].father = fa;
	}
	else if (fa > fb) {
		s[fb].father += s[fa].father;
		s[fb].sets += s[fa].sets;
		s[fb].area += s[fa].area;
		s[fa].father = fb;
	}
}
bool cmp(const int &a, const int &b) {
	if (s[a].area / (-s[a].father) != s[b].area / (-s[b].father)) return s[a].area / (-s[a].father) > s[b].area / (-s[b].father);
	return a < b;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int ID, fa, mo, k, scnt, sarea;
		cin >> ID >> fa >> mo >> k;
		if (fa != -1) Union(ID, fa);
		if (mo != -1) Union(ID, mo);
		for (int j = 0; j < k; j++) {
			int son;
			cin >> son;
			Union(ID, son);
		}
		cin >> scnt >> sarea;
		s[Find(ID)].area += sarea;
		s[Find(ID)].sets += scnt;
	}
	vector<int>out;
	unordered_map<int, bool>isout;
	for (auto it = s.begin(); it != s.end(); it++) if (!isout[Find(it->first)]) {
		isout[Find(it->first)] = true;
		out.push_back(Find(it->first));
	}
	cout << out.size() << endl;
	sort(out.begin(), out.end(), cmp);
	for (int i = 0; i < out.size(); i++) cout << setw(4) << setfill('0') << out[i] << ' ' << -s[out[i]].father << ' ' << setprecision(3) << fixed << (double)s[out[i]].sets / (-s[out[i]].father) << ' ' << setprecision(3) << fixed << s[out[i]].area / (-s[out[i]].father) << endl;
	system("pause");
	return 0;
}
