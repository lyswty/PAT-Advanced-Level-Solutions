#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
int main() {
	int n, n1, n2;
	cin >> n;
	n1 = n / 2;
	n2 = n - n1;
	vector<int>s(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	sort(s.begin(), s.end());
	int s1 = accumulate(s.begin(), s.begin() + n1, 0), s2 = accumulate(s.begin() + n1, s.end(), 0);
	cout << n2 - n1 << ' ' << s2 - s1;
	system("pause");
	return 0;
}
