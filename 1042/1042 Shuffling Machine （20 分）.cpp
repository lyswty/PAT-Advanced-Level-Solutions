#include<iostream>
#include<string>
#include<vector>
using namespace std;
int op[54];
string conv(int x) {
	string a;
	if (x < 13) {
		a = 'S';
		a += to_string(x + 1);
	}
	else if (x < 26) {
		a = 'H';
		a += to_string(x - 12);
	}
	else if (x < 39) {
		a = 'C';
		a += to_string(x - 25);
	}
	else if (x < 52) {
		a = 'D';
		a += to_string(x - 38);
	}
	else {
		a = 'J';
		a += to_string(x - 51);
	}
	return a;
}
vector<string> shuffle(vector<string> a) {
	vector<string> b = a;
	for (int i = 0; i < 54; i++) b[op[i]] = a[i];
	return b;
}
int main() {
	vector<string>order(54);
	int n;
	cin >> n;
	for (int i = 0; i < 54; i++) {
		order[i] = conv(i);
		cin >> op[i];
		op[i]--;
	}
	while (n--) order = shuffle(order);
	for (int i = 0; i < 54; i++) {
		cout << order[i];
		if (i != 53) cout << ' ';
	}
	system("pause");
	return 0;
}
