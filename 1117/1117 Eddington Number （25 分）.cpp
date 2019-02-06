#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
int main() {
	int n, i;
	cin >> n;
	int *miles = new int[n];
	for (int i = 0; i < n; i++) cin >> miles[i];
	sort(miles, miles + n, greater<int>());
	for (i = 0; miles[i] > i + 1; i++);
	cout << i;
	system("pause");
	return 0;
}
