#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	double a[3][3], out = 0.65;
	int best[3];
	char s[3] = { 'W','T','L' };
	for (int i = 0; i < 3; i++) {
		double max = 0.0;
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
			if (a[i][j] > max) {
				max = a[i][j];
				best[i] = j;
			}
		}
		cout << s[best[i]] << ' ';
		out *= a[i][best[i]];
	}
	out = 2 * (out - 1);
	cout << setprecision(2) << fixed << out;
	system("pause");
	return 0;
}
