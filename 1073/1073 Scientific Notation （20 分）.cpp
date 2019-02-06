#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string x, y, z;
	cin >> x;
	if (x[0] == '-') y = "-";
	x = x.substr(1);
	int e = x.find('E');
	z = x.substr(0, e);
	int point = z.find('.');
	int n = stoi(x.substr(e + 1));
	z.erase(find(z.begin(), z.end(), '.'));
	if (point + n <= 0) {
		y += "0.";
		for (int i = 0; i < -point - n; i++) y += '0';
		y += z;
	}
	else if (point + n < z.size()) {
		z.insert(point + n, ".");
		string::iterator it;
		for (it = z.begin(); it != z.end() && *it == '0'; it++);
		if (it == z.end() || *it == '.') z.erase(z.begin(), it - 1);
		else z.erase(z.begin(), it);
		y += z;
	}
	else {
		int m = z.size();
		string::iterator it;
		for (it = z.begin(); it != z.end() && *it == '0'; it++);
		if (it == z.end()) {
			y.clear();
			z.erase(z.begin(), it - 1);
		}
		else z.erase(z.begin(), it);
		y += z;
		for (int i = 0; i < point + n - m; i++) y += '0';
	}
	cout << y;
	system("pause");
	return 0;
}
