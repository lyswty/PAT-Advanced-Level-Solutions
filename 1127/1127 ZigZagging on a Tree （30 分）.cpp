#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef struct node {
	int data;
	node *left, *right;
	node() {
		left = right = NULL;
	}
}*tree;
vector<int>level, in, post, levelcnt;
tree reconstruct(int instart, int inend, int poststart, int postend) {
	int inroot;
	for (inroot = instart; in[inroot] != post[postend]; inroot++);
	tree T = new node;
	T->data = post[postend];
	if (inroot != instart) {
		int inleftstart = instart, inleftend = inroot - 1, postleftstart = poststart, postleftend = postleftstart + inleftend - inleftstart;
		T->left = reconstruct(inleftstart, inleftend, postleftstart, postleftend);
	}
	if (inroot != inend) {
		int inrightstart = inroot + 1, inrightend = inend, postrightend = postend - 1, postrightstart = postrightend - inrightend + inrightstart;
		T->right = reconstruct(inrightstart, inrightend, postrightstart, postrightend);
	}
	return T;
}
void BFS(tree T) {
	if (!T) return;
	queue<tree>q;
	tree last = T, l = last;
	int cnt = 0;
	q.push(T);
	while (q.size()) {
		tree cur = q.front();
		q.pop();
		level.push_back(cur->data);
		if (cur->left) {
			q.push(cur->left);
			l = cur->left;
			cnt++;
		}
		if (cur->right) {
			q.push(cur->right);
			l = cur->right;
			cnt++;
		}
		if (cur == last) {
			if (cnt) levelcnt.push_back(cnt);
			last = l;
			cnt = 0;
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		in.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		post.push_back(x);
	}
	tree T = reconstruct(0, n - 1, 0, n - 1);
	BFS(T);
	int i = 0;
	cout << level[0];
	for (int j = 0; j < levelcnt.size(); j++) {
		int right = i + levelcnt[j];
		if (j % 2 == 0) for (int k = i + 1; k <= right; k++) cout << ' ' << level[k];
		else for (int k = right; k > i; k--) cout << ' ' << level[k];
		i = right;
	}
	system("pause");
	return 0;
}
