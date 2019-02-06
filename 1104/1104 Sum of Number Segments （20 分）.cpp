#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int n;
	cin >> n;
	double sum = 0.0;
	for (int i = 0; i < n; i++) {
		double cur;
		cin >> cur;
		sum += cur * (i + 1) * (n - i);
	}
	cout << setprecision(2) << fixed << sum;
	system("pause");
	return 0;
}
