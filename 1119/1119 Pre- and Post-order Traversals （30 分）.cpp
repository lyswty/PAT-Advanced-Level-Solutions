#include<iostream>
#include<vector>
using namespace std;
typedef struct node {
	int data;
	node *left, *right;
	node() {
		left = right = NULL;
	}
}*tree;
vector<int>pre, in, post;
bool is = true;
tree reconstruct(int prestart, int preend, int poststart, int postend) {
	tree T = new node;
	T->data = pre[prestart];
	if (prestart < preend)
		if (pre[prestart + 1] == post[postend - 1]) {
			is = false;
			T->left = reconstruct(prestart + 1, preend, poststart, postend - 1);
		}
		else {
			int preleftstart = prestart + 1, postrightend = postend - 1, postrightstart, postleftstart = poststart, postleftend, preleftend, prerightstart, prerightend = preend;
			for (postleftend = poststart; post[postleftend] != pre[preleftstart]; postleftend++);
			postrightstart = postleftend + 1;
			preleftend = preleftstart + postleftend - postleftstart;
			prerightstart = preleftend + 1;
			T->left = reconstruct(preleftstart, preleftend, postleftstart, postleftend);
			T->right = reconstruct(prerightstart, prerightend, postrightstart, postrightend);
		}
	return T;
}
void inDFS(tree T) {
	if (!T) return;
	if (T->left) inDFS(T->left);
	in.push_back(T->data);
	if (T->right) inDFS(T->right);
}
int main() {
	int n;
	cin >> n;
	pre.resize(n);
	post.resize(n);
	for (int i = 0; i < n; i++) cin >> pre[i];
	for (int i = 0; i < n; i++) cin >> post[i];
	tree T = NULL;
	T = reconstruct(0, n - 1, 0, n - 1);
	inDFS(T);
	if (is) cout << "Yes" << endl;
	else cout << "No" << endl;
	for (int i = 0; i < n; i++) {
		cout << in[i];
		if (i != n - 1) cout << ' ';
		else cout << endl;
	}
	system("pause");
	return 0;
}
