#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int main() {
	string a, b;
	cin >> a;
	int flag = 0;
	b = a;
	for (int i = b.size() - 1; i >= 0; i--) {
		int cur = 2 * (b[i] - '0') + flag;
		if (cur > 9) flag = 1;
		else flag = 0;
		b[i] = cur % 10 + '0';
	}
	if (flag) b = '1' + b;
	sort(a.begin(), a.end());
	string c = b;
	sort(c.begin(), c.end());
	if (a == c) cout << "Yes" << endl;
	else cout << "No" << endl;
	cout << b;
	system("pause");
	return 0;
}
