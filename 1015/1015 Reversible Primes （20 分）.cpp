#include<iostream>
#include<string>
#include<cmath>
using namespace std;
bool isprime(int x) {
	if (x < 2) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i <= sqrt(x); i += 2) if (x%i == 0) return false;
	return true;
}
int main() {
	while (true) {
		int x, d;
		cin >> x;
		if (x >= 0) {
			cin >> d;
			if (!isprime(x)) cout << "No" << endl;
			else {
				string a;
				int y = 0;
				while (x) {
					a += x % d + '0';
					x /= d;
				}
				for (int i = 0; i < a.size(); i++) y += (a[i] - '0') * pow(d, a.size() - 1 - i);
				if (isprime(y)) cout << "Yes" << endl;
				else cout << "No" << endl;
			}
		}
		else break;
	}
	system("pause");
	return 0;
}
