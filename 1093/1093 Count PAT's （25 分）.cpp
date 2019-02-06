#include<iostream>
#include<string>
using namespace std;
int main() {
	string x;
	cin >> x;
	long long p = 0, a = 0, t = 0;
	for (int i = 0; i < x.size(); i++) {
		switch (x[i]) {
		case 'P': p++; break;
		case 'A': a += p; break;
		case 'T': t += a; break;
		}
	}
	cout << t % 1000000007;
	system("pause");
	return 0;
}
