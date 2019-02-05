#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
bool out[101][10001];
int main() {
	int n, m;
	cin >> n >> m;
	int *dp = new int[m + 1], *coins = new int[n];
	for (int i = 0; i < n; i++) cin >> coins[i];
	fill(dp, dp + m + 1, 0);
	memset(out, false, sizeof(out));
	sort(coins, coins + n);
	for (int i = n - 1; i >= 0; i--) for (int v = m; v >= coins[i]; v--) 
		if (dp[v] <= dp[v - coins[i]] + coins[i]) {
			dp[v] = dp[v - coins[i]] + coins[i];
			out[v][i] = true;
		}
	if (dp[m] != m) cout << "No Solution";
	else {
		vector<int>output;
		int i = -1, v = m;
		while (dp[v]) {
			for (i++; !out[v][i]; i++);
			v -= coins[i];
			output.push_back(coins[i]);
		}
		for (int i = 0; i < output.size(); i++) {
			cout << output[i];
			if (i != output.size() - 1) cout << ' ';
		}
	}
	system("pause");
	return 0;
}
