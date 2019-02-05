#include<iostream>
using namespace std;
typedef struct node {
	int data, height;
	node *left, *right;
	node() {
		left = right = NULL;
	}
}*AVL;
int getheight(AVL T) {
	if (!T) return 0;
	int HL = getheight(T->left), HR = getheight(T->right);
	return HL > HR ? HL + 1 : HR + 1;
}
AVL LLrotation(AVL A) {
	AVL B = A->left;
	A->left = B->right;
	B->right = A;
	return B;
}
AVL RRrotation(AVL A) {
	AVL B = A->right;
	A->right = B->left;
	B->left = A;
	return B;
}
AVL LRrotation(AVL A) {
	A->left = RRrotation(A->left);
	return LLrotation(A);
}
AVL RLrotation(AVL A) {
	A->right = LLrotation(A->right);
	return RRrotation(A);
}
AVL insert(AVL T, int x) {
	if (!T) {
		T = new node;
		T->data = x;
		T->height = 1;
	}
	else {
		if (x < T->data) {
			T->left = insert(T->left, x);
			if (getheight(T->left) - getheight(T->right) == 2)
				if (x < T->left->data) T = LLrotation(T);
				else T = LRrotation(T);
		}
		else {
			T->right = insert(T->right, x);
			if (getheight(T->right) - getheight(T->left) == 2)
				if (x < T->right->data) T = RLrotation(T);
				else T = RRrotation(T);
		}
	}
	return T;
}
int main() {
	int n;
	cin >> n;
	AVL T = NULL;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		T = insert(T, x);
	}
	cout << T->data;
	system("pause");
	return 0;
}
