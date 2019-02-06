#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector<int>pre, in;
deque<int>post;
void getpost(int prestart, int preend, int instart, int inend) {
	int inroot;
	for (inroot = instart; in[inroot] != pre[prestart]; inroot++);
	post.push_front(pre[prestart]);
	if (inroot != inend) {
		int inrightstart = inroot + 1, inrightend = inend, prerightend = preend, prerightstart = prerightend - inrightend + inrightstart;
		getpost(prerightstart, prerightend, inrightstart, inrightend);
	}
	if (inroot != instart) {
		int inleftstart = instart, inleftend = inroot - 1, preleftstart = prestart + 1, preleftend = preleftstart + inleftend - inleftstart;
		getpost(preleftstart, preleftend, inleftstart, inleftend);
	}
}
int main() {
	int n;
	cin >> n;
	pre.resize(n);
	in.resize(n);
	for (int i = 0; i < n; i++) cin >> pre[i];
	for (int i = 0; i < n; i++) cin >> in[i];
	getpost(0, n - 1, 0, n - 1);
	cout << post[0];
	system("pause");
	return 0;
}
