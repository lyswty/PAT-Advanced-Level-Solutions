#include<iostream>
#include<unordered_map>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, n;
	cin >> m >> n;
	int half = m * n / 2, d;
	unordered_map<int, int>mp;
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
		int cur;
		cin >> cur;
		mp[cur]++;
		if (mp[cur] > half) d = cur;
	}
	cout << d;
	system("pause");
	return 0;
}
