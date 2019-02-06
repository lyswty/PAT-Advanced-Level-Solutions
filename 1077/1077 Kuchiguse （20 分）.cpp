#include<iostream>
#include<string>
using namespace std;
int main() {
	int n, min = 257, l;
	cin >> n;
	getchar();
	string *s = new string[n];
	for (int i = 0; i < n; i++) {
		getline(cin, s[i]);
		if (s[i].size() < min) min = s[i].size();
	}
	for (l = 0; l < min; l++) {
		bool flag = false;
		for (int i = 1; i < n; i++) if (s[i][s[i].size() - 1 - l] != s[0][s[0].size() - 1 - l]) {
			flag = true;
			break;
		}
		if (flag) break;
	}
	if (!l) cout << "nai";
	else cout << s[0].substr(s[0].size() - l);
	delete[] s;
	system("pause");
	return 0;
}
