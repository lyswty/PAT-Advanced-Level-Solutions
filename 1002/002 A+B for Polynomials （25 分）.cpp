#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;
double a[1001];
int main() {
	fill(a, a + 1001, 0.0);
	int k;
	vector<int>expons;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int e;
		double c;
		cin >> e >> c;
		a[e] += c;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int e;
		double c;
		cin >> e >> c;
		a[e] += c;
	}
	for (int i = 1000; i >= 0; i--) if (a[i] != 0) expons.push_back(i);
	cout << expons.size();
	if (expons.size()) cout << ' ';
	for (int i = 0; i < expons.size(); i++) {
		cout << expons[i] << ' ' << setprecision(1) << fixed << a[expons[i]];
		if (i != expons.size() - 1) cout << ' ';
	}
	system("pause");
	return 0;
}
