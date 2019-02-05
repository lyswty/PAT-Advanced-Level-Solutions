#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	long long n, b;
	cin >> n >> b;
	vector<long long>a1, a2;
	if (!n) a1.push_back(0);
	while (n) {
		a1.push_back(n % b);
		n /= b;
	}
	a2 = a1;
	reverse(a1.begin(), a1.end());
	if (a1 == a2) cout << "Yes" << endl;
	else cout << "No" << endl;
	for (int i = 0; i < a1.size(); i++) {
		cout << a1[i];
		if (i != a1.size() - 1) cout << ' ';
	}
	system("pause");
	return 0;
}
