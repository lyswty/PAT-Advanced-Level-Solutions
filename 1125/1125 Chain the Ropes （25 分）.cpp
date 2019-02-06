#include<queue>
#include<iostream>
#include<functional>
using namespace std;
int main() {
	priority_queue<int, vector<int>, greater<int>>ropes;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		ropes.push(cur);
	}
	while (ropes.size() > 1) {
		int a = ropes.top();
		ropes.pop();
		int b = ropes.top();
		ropes.pop();
		ropes.push((a + b) / 2);
	}
	cout << ropes.top();
	system("pause");
	return 0;
}
