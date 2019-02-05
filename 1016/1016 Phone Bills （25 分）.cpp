#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;
struct record {
	int hh, mm, dd;
	bool on_off;
};
struct customer {
	string name;
	int month;
	vector<record>records;
};
int toll[24];
bool cmp(const record &a, const record &b) {
	return a.dd * 24 * 60 + a.hh * 60 + a.mm < b.dd * 24 * 60 + b.hh * 60 + b.mm;
}
pair<int, double> calculate(const record &a, const record &b) {
	int total = 0;
	int min = 0;
	int oneday = 0;
	for (int i = 0; i < 24; i++) oneday += toll[i] * 60;
	total += (60 - a.mm) * toll[a.hh];
	min += 60 - a.mm + (23 - a.hh) * 60;
	for (int i = a.hh + 1; i < 24; i++) total += toll[i] * 60;
	total += oneday * (b.dd - a.dd - 1);
	min += (b.dd - a.dd - 1) * 24 * 60;
	for (int i = 0; i < b.hh; i++) total += toll[i] * 60;
	total += toll[b.hh] * b.mm;
	min += b.hh * 60 + b.mm;
	return make_pair(min, (double)total / 100);
}
int main() {
	map<string, customer>mp;
	for (int i = 0; i < 24; i++) scanf("%d", &toll[i]);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string name, state;
		int Mon;
		record cur;
		cin >> name;
		scanf("%d:%d:%d:%d", &Mon, &cur.dd, &cur.hh, &cur.mm);
		cin >> state;
		if (state[1] == 'n') cur.on_off = true;
		else cur.on_off = false;
		mp[name].name = name;
		mp[name].month = Mon;
		mp[name].records.push_back(cur);
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		double total = 0.0;
		sort(it->second.records.begin(), it->second.records.end(), cmp);
		vector<pair<record, record>>out;
		for (int i = 1; i < it->second.records.size(); i++) if (!it->second.records[i].on_off&&it->second.records[i - 1].on_off) out.push_back(make_pair(it->second.records[i - 1], it->second.records[i]));
		if (out.size()) {
			cout << it->first << ' ' << setw(2) << setfill('0') << it->second.month << endl;
			for (int i = 0; i < out.size(); i++) {
				pair<int, double>cur = calculate(out[i].first, out[i].second);
				total += cur.second;
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", out[i].first.dd, out[i].first.hh, out[i].first.mm, out[i].second.dd, out[i].second.hh, out[i].second.mm, cur.first, cur.second);
			}
			printf("Total amount: $%.2f\n", total);
		}
	}
	system("pause");
	return 0;
}
