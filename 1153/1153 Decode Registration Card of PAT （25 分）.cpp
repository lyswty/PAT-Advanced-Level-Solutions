#include<iostream>
#include<string>
#include<unordered_map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
struct testee {
	string cardnumber;
	int score;
	friend bool operator<(const testee &a, const testee &b) {
		if (a.score != b.score) return a.score > b.score;
		return a.cardnumber < b.cardnumber;
	}
};
struct mp3out {
	string sitenumber;
	int count;
	mp3out(){}
	mp3out(string sn,int x):sitenumber(sn),count(x){}
	friend bool operator<(const mp3out &a, const mp3out &b) {
		if (a.count != b.count) return a.count > b.count;
		return a.sitenumber < b.sitenumber;
	}
};
int main() {
	int n, m;
	cin >> n >> m;
	unordered_map<char, vector<testee>>mp1;
	unordered_map<string, pair<int, int>>mp2;
	unordered_map<string, pair<unordered_map<string, int>, vector<mp3out>>>mp3;
	unordered_map<char, bool>issort;
	for (int i = 0; i < n; i++) {
		testee cur;
		cin >> cur.cardnumber >> cur.score;
		mp1[cur.cardnumber[0]].push_back(cur);
		string cursite = cur.cardnumber.substr(1, 3), date = cur.cardnumber.substr(4, 6);
		mp2[cursite].first++;
		mp2[cursite].second += cur.score;
		mp3[date].first[cursite]++;
	}
	for (int i = 0; i < m; i++) {
		int op;
		string term;
		cin >> op >> term;
		cout << "Case " << i + 1 << ": " << op << ' ' << term << endl;
		if (op == 1 && mp1[term[0]].size()) {
			if (!issort[term[0]]) sort(mp1[term[0]].begin(), mp1[term[0]].end());
			for (int i = 0; i<mp1[term[0]].size(); i++) cout << mp1[term[0]][i].cardnumber << ' ' << mp1[term[0]][i].score << endl;
		}
		else if (op == 2 && mp2[term].first > 0) cout << mp2[term].first << ' ' << mp2[term].second << endl;
		else if (op == 3 && mp3[term].first.size()) {
			if (!mp3[term].second.size()) {
				for (auto it = mp3[term].first.begin(); it != mp3[term].first.end(); it++) mp3[term].second.push_back(mp3out(it->first, it->second));
				sort(mp3[term].second.begin(), mp3[term].second.end());
			}
			for (int i = 0; i < mp3[term].second.size(); i++) cout << mp3[term].second[i].sitenumber << ' ' << mp3[term].second[i].count << endl;
		}
		else cout << "NA" << endl;
	}
	system("pause");
	return 0;
}
