#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main() {
	int n;
	cin >> n;
	getchar();
	string one[13] = { "" ,"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	string two[13] = { "","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	for (int i = 0; i < n; i++) {
		string cur;
		getline(cin, cur);
		stringstream ss;
		ss.str(cur);
		if (isdigit(cur[0])) {
			int x;
			ss >> x;
			if (!x) cout << "tret";
			else if (x >= 13) {
				cout << two[x / 13];
				if (x % 13) cout << ' ' << one[x % 13];
			}
			else cout << one[x];
			cout << endl;
		}
		else {
			int out = 0;
			while (ss >> cur) {
				for (int j = 0; j < 14; j++) if (two[j] == cur) {
					out += j * 13;
					break;
				}
				for (int j = 0; j < 14; j++) if (one[j] == cur) {
					out += j;
					break;
				}
			}
			cout << out << endl;
		}
	}
	system("pause");
	return 0;
}
