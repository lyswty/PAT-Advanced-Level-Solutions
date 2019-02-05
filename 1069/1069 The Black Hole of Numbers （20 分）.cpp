#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<functional>
#include<iomanip>
using namespace std;
int main() {
	int d;
	string x;
	cin >> d;
	stringstream ss;
	ss << setw(4) << setfill('0') << d;
	ss >> x;
	do {
		ss.clear();
		ss.str("");
		string y = x, z = x;
		sort(z.begin(), z.end());
		sort(y.begin(), y.end(), greater<char>());
		ss << setw(4) << setfill('0') << stoi(y) - stoi(z);
		x = ss.str();
		cout << y << " - " << z << " = " << x << endl;
	} while (x != "6174" && x != "0000");
	system("pause");
	return 0;
}
