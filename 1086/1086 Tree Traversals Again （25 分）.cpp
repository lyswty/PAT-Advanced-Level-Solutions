#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<int>pre, in, post;
void getpost(int prestart, int preend, int instart, int inend) {
	int inroot = distance(in.begin(), find(in.begin(), in.end(), pre[prestart]));
	if (inroot != instart) {
		int inleftstart = instart, inleftend = inroot - 1, preleftstart = prestart + 1, preleftend = preleftstart + inleftend - inleftstart;
		getpost(preleftstart, preleftend, inleftstart, inleftend);
	}
	if (inroot != inend) {
		int inrightstart = inroot + 1, inrightend = inend, prerightend = preend, prerightstart = prerightend - inrightend + inrightstart;
		getpost(prerightstart, prerightend, inrightstart, inrightend);
	}
	post.push_back(pre[prestart]);
}
int main() {
	int n;
	cin >> n;
	stack<int>s;
	for (int i = 0; i < 2 * n; i++) {
		string op;
		cin >> op;
		if (op[1] == 'u') {
			int x;
			cin >> x;
			s.push(x);
			pre.push_back(x);
		}
		else {
			in.push_back(s.top());
			s.pop();
		}
	}
	getpost(0, n - 1, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << post[i];
		if (i != n - 1) cout << ' ';
	}
	system("pause");
	return 0;
}
