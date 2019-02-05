#include<iostream>
#include<string>
#include<unordered_map>
#include<set>
#include<vector>
#include<sstream>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<unordered_map<string, set<string>>>v(6);
	for (int i = 0; i < n; i++) {
		string author, title, keywords, year, publisher, keyword;
		string ID;
		cin >> ID;
		getchar();
		getline(cin, title);
		getline(cin, author);
		getline(cin, keywords);
		getline(cin, publisher);
		getline(cin, year);
		v[1][title].insert(ID);
		v[2][author].insert(ID);
		stringstream ss;
		ss.str(keywords);
		while (ss >> keyword) v[3][keyword].insert(ID);
		v[4][publisher].insert(ID);
		v[5][year].insert(ID);
	}
	int k;
	cin >> k;
	getchar();
	while (k--) {
		string cur;
		getline(cin, cur);
		cout << cur << endl;
		int op = cur[0] - '0';
		string index = cur.substr(3);
		if (v[op][index].size()) for (auto it = v[op][index].begin(); it != v[op][index].end(); it++) cout << *it << endl;
		else cout << "Not Found" << endl;
	}
	system("pause");
	return 0;
}
