#include<iostream>
#include<stack>
using namespace std;
int main() {
	int m, n, k;
	bool flag;
	cin >> m >> n >> k;
	int *seq = new int[n];
	while (k--) {
		flag = true;
		stack<int>s;
		for (int i = 0; i < n; i++) cin >> seq[i];
		s.push(1);
		int cur = 2;
		for (int i = 0; i < n; i++) {
			while (s.empty() || s.top() != seq[i]) {
				s.push(cur++);
				if (s.size() > m) {
					flag = false;
					break;
				}
			}
			if (!flag) break;
			s.pop();
		}
		if (!flag) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	system("pause");
	return 0;
}
