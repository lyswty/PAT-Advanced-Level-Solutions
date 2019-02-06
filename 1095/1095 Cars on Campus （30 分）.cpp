#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
bool cmpcar(const pair<int, bool> &a, const pair<int, bool> &b) {
	return a.first < b.first;
}
bool cmprecord(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first != b.first) return a.first < b.first;
	return a.second < b.second;
}
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	unordered_map<string, vector<pair<int, bool>>>car;
	vector<pair<int, int>>records;
	for (int i = 0; i < n; i++) {
		string plate_number;
		char pn[10], op[4];
		int hh, mm, ss;
		scanf("%s %02d:%02d:%02d %s", pn, &hh, &mm, &ss, op);
		plate_number = pn;
		ss += mm * 60 + hh * 3600;
		if (op[0] == 'i') car[plate_number].push_back(make_pair(ss, true));
		else car[plate_number].push_back(make_pair(ss, false));
	}
	vector<string>maxcar;
	int max = 0;
	for (auto it = car.begin(); it != car.end(); it++) {
		int time = 0;
		sort(it->second.begin(), it->second.end(), cmpcar);
		for (int i = 1; i < it->second.size(); i++) if (!it->second[i].second && it->second[i - 1].second) {
			time += it->second[i].first - it->second[i - 1].first;
			records.push_back(make_pair(it->second[i - 1].first, it->second[i].first));
		}
		if (time > max) {
			max = time;
			maxcar.clear();
			maxcar.push_back(it->first);
		}
		else if (time == max) maxcar.push_back(it->first);
	}
	sort(records.begin(), records.end(), cmprecord);
	int last, j = 0, start = 0;
	for (int i = 0; i < q; i++) {
		last = 0;
		bool flag = false;
		int hh, mm, ss;
		scanf("%02d:%2d:%02d", &hh, &mm, &ss);
		ss += hh * 3600 + mm * 60;
		for (j = start; j < records.size(); j++) {
			if (records[j].first <= ss && records[j].second > ss) {
				last++;
				if (!flag) {
					start = j;
					flag = true;
				}
			}
			if (records[j].first > ss) break;
		}
		printf("%d\n", last);
	}
	sort(maxcar.begin(), maxcar.end());
	for (int i = 0; i < maxcar.size(); i++) printf("%s ",maxcar[i].c_str());
	printf("%02d:%02d:%02d", max / 3600, max % 3600 / 60, max % 60);
	system("pause");
	return 0;
}
