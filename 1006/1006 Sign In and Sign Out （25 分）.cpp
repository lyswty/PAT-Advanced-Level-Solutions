#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
struct Time {
	int hour;
	int minute;
	int second;
};
struct record {
	string ID;
	Time signin;
	Time signout;
};
bool Signin(const record &a, const record &b) {
	if (a.signin.hour != b.signin.hour) return a.signin.hour < b.signin.hour;
	if (a.signin.minute != b.signin.minute) return a.signin.minute < b.signin.minute;
	return a.signin.second < b.signin.second;
}
bool Signout(const record &a, const record &b) {
	if (a.signout.hour != b.signout.hour) return a.signout.hour > b.signout.hour;
	if (a.signout.minute != b.signout.minute) return a.signout.minute > b.signout.minute;
	return a.signout.second > b.signout.second;
}
int main() {
	int n;
	vector<record>v;
	cin >> n;
	while (n--) {
		record cur;
		cin >> cur.ID;
		scanf("%d:%d:%d", &cur.signin.hour, &cur.signin.minute, &cur.signin.second);
		scanf("%d:%d:%d", &cur.signout.hour, &cur.signout.minute, &cur.signout.second);
		v.push_back(cur);
	}
	sort(v.begin(), v.end(), Signin);
	cout << v[0].ID << ' ';
	sort(v.begin(), v.end(), Signout);
	cout << v[0].ID;
	system("pause");
	return 0;
}
