#include<iostream>
using namespace std;
int dp[201][10001] = { 0 };
int main() {
	int n, m, l;
	cin >> l >> n;
	int *a = new int[n + 1];
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	int *b = new int[m + 1];
	for (int i = 1; i <= m; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		int max = dp[i - 1][j - 1];
		if (dp[i][j - 1] > max) max = dp[i][j - 1];
		if (dp[i - 1][j] > max)max = dp[i - 1][j];
		if (b[j] == a[i]) dp[i][j] = max + 1;
		else dp[i][j] = max;
	}
	cout << dp[n][m];
	system("pause");
	return 0;
}
