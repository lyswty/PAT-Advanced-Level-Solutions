#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n, max = 0, start;
	cin >> n;
	for (int i = 2; i < sqrt(n); i++) if (n % i == 0) {
		int m = n / i, end;
		for (end = i + 1; m % end == 0; m /= end, end++);
		if (end - i > max) {
			max = end - i;
			start = i;
		}
	}
	if (!max) cout << 1 << endl << n;
	else {
		cout << max << endl << start;
		for (int i = start + 1; i < start + max; i++) cout << '*' << i;
	}
	system("pause");
	return 0;
}
