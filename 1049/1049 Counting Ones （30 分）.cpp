#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main() {
	string n;
	cin >> n;
	int total = 0;
	if (n == "0") cout << 0;
	else if (n == "1") cout << 1;
	else {
		if (n[0] == '1') total += stoi(n.substr(1)) + 1;
		else total += pow(10, n.size() - 1);
		for (int i = 1; i < n.size(); i++) {
			switch (n[i]) {
			case '0': total += pow(10, n.size() - 1 - i) * stoi(n.substr(0, i)); break;
			case '1': total += pow(10, n.size() - 1 - i) * stoi(n.substr(0, i)); break;
			default: total += pow(10, n.size() - 1 - i) * (stoi(n.substr(0, i)) + 1);
			}
			if (n[i] == '1')
				if (i != n.size() - 1) total += stoi(n.substr(i + 1)) + 1;
				else total += 1;
		}
		cout << total;
	}
	system("pause");
	return 0;
}
