#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
#include<algorithm>
using namespace std;
int main() {
	int n, cnt = 0;
	cin >> n;
	double sum = 0.0;
	for (int i = 0; i < n; i++) {
		bool flag = true;
		string cur;
		cin >> cur;
		if (count(cur.begin(), cur.end(), '.') > 1) flag = false;
		else if (distance(find(cur.begin(), cur.end(), '.'), cur.end()) > 3) flag = false;
		else {
			stringstream ss;
			ss.str(cur);
			double x;
			if (!(ss >> x)) flag = false;
			else if (x > 1000 || x < -1000) flag = false;
			else {
				sum += x;
				cnt++;
			}
		}
		if (!flag) cout << "ERROR: " << cur << " is not a legal number" << endl;
	}
	if (!cnt) cout << "The average of 0 numbers is Undefined";
	else if (cnt > 1) cout << "The average of " << cnt << " numbers is " << setprecision(2) << fixed << sum / cnt;
	else cout << "The average of 1 number is " << setprecision(2) << fixed << sum;
	system("pause");
	return 0;
}
