#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		cout << "Case #" << i + 1 << ": ";
		if (a > 0 && b > 0 && a + b < a) cout << "true" << endl;
		else if (a < 0 && b < 0 && a + b > a) cout << "false" << endl;
		else if (a + b > c) cout << "true" << endl;
		else cout << "false" << endl;
	}
	system("pause");
	return 0;
}
