#include<iostream>
#include<string>
#include<utility>
#include<vector>
using namespace std;
bool judge(string &a) {
	bool flag = false;
	for (int i = 0; i < a.size(); i++) {
		switch (a[i]) {
		case '1': a[i] = '@'; flag = true; break;
		case '0': a[i] = '%'; flag = true; break;
		case 'l': a[i] = 'L'; flag = true; break;
		case 'O': a[i] = 'o'; flag = true;
		}
	}
	return flag;
}
int main() {
	int n;
	cin >> n;
	vector<pair<string, string>>output;
	for (int i = 0; i < n; i++) {
		string ID, password;
		cin >> ID >> password;
		if (judge(password)) output.push_back(pair<string, string>(ID, password));
	}
	if (output.size()) {
		cout << output.size() << endl;
		for (int i = 0; i < output.size(); i++) cout << output[i].first << ' ' << output[i].second << endl;
	}
	else if (n == 1) cout << "There is 1 account and no account is modified" << endl;
	else cout << "There are " << n << " accounts and no account is modified" << endl;
	system("pause");
	return 0;
}
