#include<iostream>
#include<algorithm>
#include<utility>
#include<iomanip>
using namespace std;
bool cmp(const pair<double, double>&a, pair<double, double>&b) {
	return a.second > b.second;
}
int main() {
	int n;
	double m, exp = 0.0;
	cin >> n >> m;
	pair<double, double> *mooncakes = new pair<double, double>[n];
	for (int i = 0; i < n; i++) cin >> mooncakes[i].first;
	for (int i = 0; i < n; i++) {
		double price;
		cin >> price;
		mooncakes[i].second = price / mooncakes[i].first;
	}
	sort(mooncakes, mooncakes + n, cmp);
	for (int i = 0; i < n; i++)
		if (mooncakes[i].first >= m) {
			exp += m * mooncakes[i].second;
			break;
		}
		else {
			exp += mooncakes[i].first * mooncakes[i].second;
			m -= mooncakes[i].first;
		}
	cout << setprecision(2) << fixed << exp;
	delete[] mooncakes;
	system("pause");
	return 0;
}
