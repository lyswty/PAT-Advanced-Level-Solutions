#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, m;
	bool flag = false;
	cin >> n >> m;
	int *coins = new int[n];
	for (int i = 0; i < n; i++) cin >> coins[i];
	sort(coins, coins + n);
	for (int i = 0; i < n && coins[i] <= m / 2; i++) {
		int *j = lower_bound(coins + i + 1, coins + n, m - coins[i]);
		if (*j == m - coins[i]) {
			cout << coins[i] << ' ' << *j;
			flag = true;
			break;
		}
	}
	if (!flag) cout << "No Solution";
	system("pause");
	return 0;
}
