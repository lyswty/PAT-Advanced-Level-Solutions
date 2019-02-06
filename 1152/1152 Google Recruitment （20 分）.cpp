#include<iostream>
#include<string>
#include<cmath>
using namespace std;
bool isprime(int x) {
	if (x < 2) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i <= sqrt(x); i += 2) if (x % i == 0) return false;
	return true;
}
int main() {
	int n, k, flag = 0;
	string num;
	cin >> n >> k >> num;
	for (int i = 0; i <= n - k; i++) {
		string s = num.substr(i, k);
		int x = stoi(s);
		if (isprime(x)) {
			cout << s << endl;
			flag = 1;
			break;
		}
	}
	if (!flag) cout << 404 << endl;
	system("pause");
	return 0;
}
