#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	int n;
	bool ins = true;
	cin >> n;
	vector<int>a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	int i;
	for (i = 1; i < n; i++) if (b[i] < b[i - 1]) break;
	for (int j = i; j < n; j++) if (a[j] != b[j]) ins = false;
	if (ins) {
		cout << "Insertion Sort" << endl;
		sort(b.begin(), b.begin() + i + 1);
	}
	else {
		cout << "Merge Sort" << endl;
		int min = n, cur = 1;
		for (int i = 1; i < n; i++) {
			if (b[i] >= b[i - 1]) cur++;
			else {
				if (cur < min) min = cur;
				cur = 1;
			}
		}
		min *= 2;
		int j;
		for (j = 0; j + min <= n; j += min) sort(b.begin() + j, b.begin() + j + min);
		if (j < n - 1) sort(b.begin() + j, b.end());
	}
	for (int i = 0; i < n; i++) {
		cout << b[i];
		if (i != n - 1) cout << ' ';
	}
	system("pause");
	return 0;
}
