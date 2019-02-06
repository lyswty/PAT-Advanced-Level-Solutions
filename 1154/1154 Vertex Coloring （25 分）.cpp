#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main() {
	int n, m, k;
	cin >> n >> m;
	vector<pair<int,int>>E(m);
	for (int i = 0; i < m; i++) cin >> E[i].first >> E[i].second;
	cin >> k;
	while (k--) {
		vector<int>color(n);
		unordered_set<int>colorset;
		bool k_coloring = true;
		for (int i = 0; i < n; i++) {
			cin >> color[i];
			colorset.insert(color[i]);
		}
		for (int i = 0; i < m; i++) if (color[E[i].first] == color[E[i].second]) {
			k_coloring = false;
			break;
		}
		if (k_coloring) cout << colorset.size() << "-coloring" << endl;
		else cout << "No" << endl;
	}
	system("pause");
	return 0;
}
