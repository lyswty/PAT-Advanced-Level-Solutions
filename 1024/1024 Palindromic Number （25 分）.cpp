#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string add(string a, string b) {
	int flag = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		int cur = (a[i] - '0') + (b[i] - '0') + flag;
		if (cur > 9) flag = 1;
		else flag = 0;
		a[i] = cur % 10 + '0';
	}
	if (flag) a = '1' + a;
	return a;
}
int main() {
	string n;
	int k, step = 0;
	cin >> n >> k;
	while (step < k) {
		string m = n;
		reverse(m.begin(), m.end());
		if (m == n) break;
		n = add(m, n);
		step++;
	}
	cout << n << endl << step;
	system("pause");
	return 0;
}
