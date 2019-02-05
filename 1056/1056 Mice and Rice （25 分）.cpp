#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int>weight(n), rank(n), order(n);
	for (int i = 0; i < n; i++) cin >> weight[i];
	for (int i = 0; i < n; i++) cin >> order[i];
	while (order.size() != 1) {
		vector<int>winner;
		for (int i = 0; i < order.size(); i += m) {
			int max = 0, maxi = -1;
			for (int j = i; j < min((int)order.size(), i + m); j++) 
				if (weight[order[j]] > max) {
					max = weight[order[j]];
					if (maxi != -1) rank[maxi] = order.size() % m == 0 ? order.size() / m + 1 : order.size() / m + 2;
					maxi = order[j];
				}
				else rank[order[j]] = order.size() % m == 0 ? order.size() / m + 1 : order.size() / m + 2;
			winner.push_back(maxi);
		}
		order = winner;
	}
	rank[order[0]] = 1;
	for (int i = 0; i < n; i++) {
		cout << rank[i];
		if (i != n - 1) cout << ' ';
	}
	system("pause");
	return 0;
}
