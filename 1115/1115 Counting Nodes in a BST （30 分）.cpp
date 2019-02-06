#include<iostream>
#include<queue>
using namespace std;
typedef struct node {
	int data;
	node *left, *right;
	node() {
		left = right = NULL;
	}
}*tree;
tree insert(tree T, int x) {
	if (!T) {
		T = new node;
		T->data = x;
	}
	else if (x <= T->data) T->left = insert(T->left, x);
	else T->right = insert(T->right, x);
	return T;
}
int main() {
	int n, scnt = 0, lcnt = 1, ccnt = 0;
	cin >> n;
	tree T = NULL;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		T = insert(T, x);
	}
	tree last = T, l = last;
	queue<tree>q;
	q.push(T);
	while (q.size()) {
		tree cur = q.front();
		q.pop();
		if (cur->left) {
			q.push(cur->left);
			l = cur->left;
			ccnt++;
		}
		if (cur->right) {
			q.push(cur->right);
			l = cur->right;
			ccnt++;
		}
		if (cur == last) {
			last = l;
			if (q.size()) {
				scnt = lcnt;
				lcnt = ccnt;
				ccnt = 0;
			}
		}
	}
	cout << lcnt << " + " << scnt << " = " << lcnt + scnt;
	system("pause");
	return 0;
}
