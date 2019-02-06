#include<iostream>
using namespace std;
int Find(int s[], int x) {
	if (s[x] == x) return x;
	return s[x] = Find(s, s[x]);
}
void Union(int s[], int a, int b) {
	int fa = Find(s, a), fb = Find(s, b);
	if (fa != fb) s[fb] = fa;
}
int main() {
	int n, m;
	cin >> n >> m;
	int *s = new int[n], *ecnt = new int[n];
	for (int i = 0; i < n; i++) {
		s[i] = i;
		ecnt[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		ecnt[a]++;
		ecnt[b]++;
		Union(s, a, b);
	}
	int lastset = -1, flag = 0, odd = 0;
	for (int i = 0; i < n; i++) {
		if (ecnt[i] % 2) odd++;
		cout << ecnt[i];
		if (i != n - 1) cout << ' ';
		else cout << endl;
		if (lastset == -1 && ecnt[i]) lastset = Find(s, i);
		if (lastset != -1 && ecnt[i] && lastset != Find(s, i)) flag = 1;
	}
	if (flag || odd > 2) cout << "Non-Eulerian";
	else if (odd == 2) cout << "Semi-Eulerian";
	else cout << "Eulerian";
	delete[] s, ecnt;
	system("pause");
	return 0;
}
