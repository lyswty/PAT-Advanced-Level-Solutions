#include<iostream>
#include<vector>
#include<utility>
#include<unordered_map>
#include<algorithm>
using namespace std;
struct node {
	int ID;
	vector<int>op, sa;
};
unordered_map<int, node>G;
vector<pair<int, int>> search(int a, int b, bool same) {
	vector<pair<int, int>>output;
	for (int i = 0; i < G[a].sa.size(); i++) {
		if (G[a].sa[i] == b) continue;
		if (!same) {
			for (int j = 0; j < G[G[a].sa[i]].op.size(); j++) if (find(G[G[G[a].sa[i]].op[j]].sa.begin(), G[G[G[a].sa[i]].op[j]].sa.end(), b) != G[G[G[a].sa[i]].op[j]].sa.end()) output.push_back(make_pair(abs(G[a].sa[i]), abs(G[G[a].sa[i]].op[j])));
		}
		else for (int j = 0; j < G[G[a].sa[i]].sa.size(); j++) if (G[G[a].sa[i]].sa[j] != a && find(G[G[G[a].sa[i]].sa[j]].sa.begin(), G[G[G[a].sa[i]].sa[j]].sa.end(), b) != G[G[G[a].sa[i]].sa[j]].sa.end()) output.push_back(make_pair(abs(G[a].sa[i]), abs(G[G[a].sa[i]].sa[j])));
	}
	sort(output.begin(), output.end());
	return output;
}
int main() {
	int n, m, q;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		char a[6], b[6];
		scanf("%s%s", a, b);
		if ((a[0] == '-' && b[0] != '-') || (a[0] != '-' && b[0] == '-')) {
			G[atoi(a)].op.push_back(atoi(b));
			G[atoi(b)].op.push_back(atoi(a));
		}
		else {
			G[atoi(a)].sa.push_back(atoi(b));
			G[atoi(b)].sa.push_back(atoi(a));
		}
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		char a[6], b[6];
		scanf("%s%s", a, b);
		vector<pair<int, int>>out;
		if ((a[0] == '-' && b[0] != '-') || (a[0] != '-' && b[0] == '-')) out = search(atoi(a), atoi(b), false);
		else out = search(atoi(a), atoi(b), true);
		printf("%d\n", out.size());
		for (int i = 0; i < out.size(); i++) printf("%04d %04d\n", out[i].first, out[i].second);
	}
	system("pause");
	return 0;
}
