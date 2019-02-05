#include<iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n;
	int *cycle = new int[n + 1];
	cycle[0] = 0;
	for (int i = 1; i <= n; i++) {
		int cur;
		cin >> cur;
		cycle[i] = cycle[i - 1] + cur;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2, dist;
		cin >> v1 >> v2;
		v1--, v2--;
		if (v1 > v2) dist = cycle[v1] - cycle[v2];
		else dist = cycle[v2] - cycle[v1];
		if (dist < cycle[n] - dist) cout << dist << endl;
		else cout << cycle[n] - dist << endl;
	}
	delete[] cycle;
	system("pause");
	return 0;
}
