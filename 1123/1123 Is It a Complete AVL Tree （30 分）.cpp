#include<iostream>
#include<queue>
using namespace std;
typedef struct node {
	int data, height;
	node *left, *right;
	node() {
		left = right = NULL;
	}
}*AVL;
AVL llrotation(AVL A) {
	AVL B = A->left;
	A->left = B->right;
	B->right = A;
	return B;
}
AVL rrrotation(AVL A) {
	AVL B = A->right;
	A->right = B->left;
	B->left = A;
	return B;
}
AVL rlrotation(AVL A) {
	A->right = llrotation(A->right);
	return rrrotation(A);
}
AVL lrrotation(AVL A) {
	A->left = rrrotation(A->left);
	return llrotation(A);
}
int getheight(AVL T) {
	if (!T) return 0;
	int hl = getheight(T->left), hr = getheight(T->right);
	return hl > hr ? hl + 1 : hr + 1;
}
AVL insert(AVL T, int x) {
	if (!T) {
		T = new node;
		T->data = x;
		T->height = 1;
	}
	else if (x < T->data) {
		T->left = insert(T->left, x);
		if (getheight(T->left) - getheight(T->right) == 2)
			if (x < T->left->data) T = llrotation(T);
			else T = lrrotation(T);
	}
	else if (x > T->data) {
		T->right = insert(T->right, x);
		if (getheight(T->right) - getheight(T->left) == 2)
			if (x < T->right->data) T = rlrotation(T);
			else T = rrrotation(T);
	}
	return T;
}
int main() {
	int n, cnt = 1;
	bool complete = true;
	cin >> n;
	AVL T = NULL;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		T = insert(T, x);
	}
	queue<AVL>q;
	q.push(T);
	cout << T->data;
	while (q.size()) {
		AVL cur = q.front();
		q.pop();
		if (cur->left) {
			q.push(cur->left);
			cout << ' ' << cur->left->data;
			cnt++;
		}
		else if (cnt != n) complete = false;
		if (cur->right) {
			q.push(cur->right);
			cout << ' ' << cur->right->data;
			cnt++;
		}
		else if (cnt != n) complete = false;
	}
	if (complete) cout << endl << "YES";
	else cout << endl << "NO";
	system("pause");
	return 0;
}
