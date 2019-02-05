#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<iostream>
using namespace std;
bool cmp(const string &a, const string &b) {
	return a + b < b + a;
}
int main() {
	int n, i = 0;
	cin >> n;
	vector<string>num(n);
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num.begin(), num.end(), cmp);
	string sum = accumulate(num.begin(), num.end(), string(""));
	for (i = 0; sum[i] == '0' && i < sum.size(); i++);
	if (i < sum.size()) cout << sum.substr(i);
	else cout << 0;
	system("pause");
	return 0;
}
