#include<iostream>
#include<climits>
#include<stack>
using namespace std;
int main() {
	int n;
	cin >> n;
	int *list = new int[n], *max = new int[n], *min = new int[n];
	fill(max, max + n, 0);
	fill(min, min + n, INT_MAX);
	for (int i = 0; i < n; i++) {
		cin >> list[i];
		if (!i || list[i] > max[i - 1]) max[i] = list[i];
		else max[i] = max[i - 1];
	}
	stack<int>out;
	for (int i = n - 1; i >= 0; i--) {
		if (i == n - 1 || list[i] < min[i + 1]) min[i] = list[i];
		else min[i] = min[i + 1];
		if (min[i] == max[i]) out.push(list[i]);
	}
	cout << out.size() << endl;
	while (out.size()) {
		cout << out.top();
		out.pop();
		if (out.size()) cout << ' ';
	}
	cout<<endl;
	delete[] list, max, min;
	system("pause");
	return 0;
}
