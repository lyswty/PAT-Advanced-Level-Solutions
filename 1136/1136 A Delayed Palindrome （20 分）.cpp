#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string Plus(const string &a, const string &b) {
	string c;
	c.resize(a.size());
	int one = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		c[i] = (a[i] - '0' + b[i] - '0' + one) % 10 + '0';
		if (a[i] - '0' + b[i] - '0' + one > 9) one = 1;
		else one = 0;
	}
	if (one) c = '1' + c;
	return c;
}
int main() {
	string x;
	int i;
	cin >> x;
	for (i = 0; i < 10; i++) {
		string b;
		b.resize(x.size());
		reverse_copy(x.begin(), x.end(), b.begin());
		if (x == b) break;
		string c = Plus(x, b);
		cout << x << " + " << b << " = " << c << endl;
		x = c;
	}
	if (i < 10) cout << x << " is a palindromic number.";
	else cout << "Not found in 10 iterations.";
	system("pause");
	return 0;
}
