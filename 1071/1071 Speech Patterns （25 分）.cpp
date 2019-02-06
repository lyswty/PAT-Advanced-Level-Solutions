#include<string>
#include<iostream>
#include<map>
using namespace std;
int main() {
	map<string, int>cnt;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) if (isupper(s[i])) s[i] = tolower(s[i]);
	int start = 0, max = 0;
	string maxs;
	while (true) {
		while (start<s.size() && !isalnum(s[start])) start++;
		if (start == s.size()) break;
		int end;
		for (end = start; end < s.size() && isalnum(s[end]); end++);
		string curs = s.substr(start, end - start);
		int cur = ++cnt[curs];
		if (cur > max) {
			max = cur;
			maxs = curs;
		}
		else if (cur == max && curs < maxs) maxs = curs;
		start = end;
	}
	cout << maxs << ' ' << max;
	system("pause");
	return 0;
}
