#include<string>
#include<iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	int h = (s.size() + 2) / 3;
	int l = s.size() + 2 - 2 * h;
	for (int i = 0; i < h - 1; i++) {
		cout << s[i];
		for (int j = 0; j < l - 2; j++) cout << ' ';
		cout << s[s.size() - 1 - i] << endl;
	}
	for (int i = h - 1; i < h + l - 1; i++) cout << s[i];
	system("pause");
	return 0;
}
