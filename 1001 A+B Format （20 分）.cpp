#include<iostream>
#include<string>
using namespace std;
int main() {
	int a, b, start = 0;
	cin >> a >> b;
	string sum = to_string(a + b);
	if (a + b < 0) start = 1;
	if (sum.size() - start == 7) {
		sum.insert(sum.begin() + start + 1, ',');
		sum.insert(sum.begin() + start + 5, ',');
	}
	else if (sum.size() - start >= 4) sum.insert(sum.end() - 3, ',');
	cout << sum << endl;
	system("pause");
	return 0;
}
