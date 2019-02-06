#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>>paths;
vector<int>curpath;
int isheap = 3;
typedef struct node {
	int data;
	node *left, *right;
	node() {
		left = right = NULL;
	}
}*tree;
tree levelcreate(int n) {
	queue<tree>q;
	tree T = new node;
	cin >> T->data;
	q.push(T);
	for (int i = 1; i < n;) {
		tree cur = q.front();
		q.pop();
		if (i < n) {
			cur->left = new node;
			cin >> cur->left->data;
			i++;
			q.push(cur->left);
		}
		if (i < n) {
			cur->right = new node;
			cin >> cur->right->data;
			i++;
			q.push(cur->right);
		}
	}
	return T;
}
void DFS(tree T) {
	curpath.push_back(T->data);
	if (!T->right && !T->left) {
		paths.push_back(curpath);
		curpath.pop_back();
		return;
	}
	if (T->right) {
		if (T->data < T->right->data) {
			if (isheap == 3) isheap = 1;
			else if (isheap == 2) isheap = 0;
		}
		else if (T->data > T->right->data) {
			if (isheap == 3) isheap = 2;
			else if (isheap == 1) isheap = 0;
		}
		DFS(T->right);
	}
	if (T->left) {
		if (T->data < T->left->data) {
			if (isheap == 3) isheap = 1;
			else if (isheap == 2) isheap = 0;
		}
		else if (T->data > T->left->data) {
			if (isheap == 3) isheap = 2;
			else if (isheap == 1) isheap = 0;
		}
		DFS(T->left);
	}
	curpath.pop_back();
}
int main() {
	int n;
	cin >> n;
	tree T = levelcreate(n);
	DFS(T);
	for (int i = 0; i < paths.size(); i++) for (int j = 0; j < paths[i].size(); j++) {
		cout << paths[i][j];
		if (j != paths[i].size() - 1) cout << ' ';
		else cout << endl;
	}
	switch (isheap) {
	case 0: cout << "Not Heap"; break;
	case 1: cout << "Min Heap"; break;
	case 2: cout << "Max Heap"; 
	}
	system("pause");
	return 0;
}
