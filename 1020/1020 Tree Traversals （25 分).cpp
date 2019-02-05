#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef struct node {
	int data;
	node *right, *left;
	node() {};
	node(int x) :data(x) {
		right = NULL;
		left = NULL;
	}
}*tree;
vector<int>in, post;
tree reconstruct(int instart, int inend, int poststart, int postend) {
	tree T = new node(post[postend]);
	int inroot;
	for (inroot = instart; in[inroot] != post[postend]; inroot++);
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
	cout << T->data;
	queue<tree>q;
	q.push(T);
	while (!q.empty()) {
		tree cur = q.front();
		q.pop();
		if (cur->left) {
			cout << ' ' << cur->left->data;
			q.push(cur->left);
		}
		if (cur->right) {
			cout << ' ' << cur->right->data;
			q.push(cur->right);
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		post.push_back(cur);
	}
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		in.push_back(cur);
	}
	tree T = reconstruct(0, n - 1, 0, n - 1);
	BFS(T);
	system("pause");
	return 0;
}
