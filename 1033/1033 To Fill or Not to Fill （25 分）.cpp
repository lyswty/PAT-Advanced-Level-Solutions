#include<iostream>
#include<iomanip>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<double, double>>station;
double cmax, d, avg, maxmile, price = 0.0, maxdist = -1.0;
int n;
void compute(int i,double fuel) {
	if (i == station.size() - 1) return;
	int j;
	for (j = i + 1; station[j].first - station[i].first <= maxmile; j++) if (station[j].second < station[i].second) break;
	if (station[j].first - station[i].first > maxmile) {
		if (j == i + 1) {
			maxdist = station[i].first + maxmile;
			return;
		}
		price += (cmax - fuel) * station[i].second;
		compute(i + 1, cmax - (station[i + 1].first - station[i].first) / avg);
	}
	else {
		if (station[j].first - station[i].first > avg * fuel) {
			price += ((station[j].first - station[i].first) / avg - fuel) * station[i].second;
			compute(j, 0);
		}
		else compute(j, fuel - (station[j].first - station[i].first) / avg);
	}
}
int main() {
	cin >> cmax >> d >> avg >> n;
	maxmile = cmax * avg;
	for (int i = 0; i < n; i++) {
		double dist, pr;
		cin >> pr >> dist;
		if (d - dist < 1e-8) continue;
		station.push_back(make_pair(dist, pr));
	}
	station.push_back(make_pair(d, 0));
	sort(station.begin(), station.end());
	if (station[0].first - 0 > 1e-8) maxdist = 0.0;
	else compute(0, 0);
	if (maxdist != -1) cout << "The maximum travel distance = " << setprecision(2) << fixed << maxdist;
	else cout << setprecision(2) << fixed << price;
	system("pause");
	return 0;
}
