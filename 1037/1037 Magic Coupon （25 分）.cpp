#include<iostream>
#include<queue>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	int sum = 0, n;
	priority_queue<int>p1, p2, n1, n2;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x > 0) p1.push(x);
		else n1.push(-x);
	}
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x > 0) p2.push(x);
		else n2.push(-x);
	}
	while (!p1.empty() && !p2.empty()) {
		sum += p1.top() * p2.top();
		p1.pop();
		p2.pop();
	}
	while (!n1.empty() && !n2.empty()) {
		sum += n1.top() * n2.top();
		n1.pop();
		n2.pop();
	}
	cout << sum;
	system("pause");
	return 0;
}
