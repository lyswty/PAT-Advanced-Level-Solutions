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
vector<int>preorder, mpreorder, postorder;
tree insert(tree T, int x) {
	if (!T) {
		T = new node;
		T->data = x;
	}
	else if (x < T->data) T->left = insert(T->left, x);
	else T->right = insert(T->right, x);
	return T;
}
void pre(tree T) {
	if (!T) return;
	preorder.push_back(T->data);
	pre(T->left);
	pre(T->right);
}
void mirrorpre(tree T) {
	if (!T) return;
	mpreorder.push_back(T->data);
	mirrorpre(T->right);
	mirrorpre(T->left);
}
void post(tree T) {
	if (!T) return;
	post(T->left);
	post(T->right);
	postorder.push_back(T->data);
}
void mirrorpost(tree T) {
	if (!T) return;
	mirrorpost(T->right);
	mirrorpost(T->left);
	postorder.push_back(T->data);
}
int main() {
	int n, ismirror = 0;
	cin >> n;
	vector<int>input(n);
	tree T = NULL;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		T = insert(T, input[i]);
	}
	pre(T);
	if (preorder == input) {
		ismirror = 1;
		post(T);
	}
	else {
		mirrorpre(T);
		if (mpreorder == input) {
			ismirror = 2;
			mirrorpost(T);
		}
	}
	if (!ismirror) cout << "NO";
	else {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			cout << postorder[i];
			if (i != n - 1) cout << ' ';
		}
	}
	system("pause");
	return 0;
}
