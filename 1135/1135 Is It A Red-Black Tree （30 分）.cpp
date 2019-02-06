#include<iostream>
#include<cmath>
using namespace std;
typedef struct node{
	int data;
	node *left,*right;
	node(){
		left=right=NULL;
	}
}*BST;
bool is;
BST insert(BST T,int x){
	if(!T){
		T=new node;
		T->data=x;
	}
	else if(abs(x)<abs(T->data)) T->left=insert(T->left,x);
	else if(abs(x)>abs(T->data)) T->right=insert(T->right,x);
	return T;
}
int DFS(BST T){
	if(!T) return 0;
	if(T->data<0){
		if(T->right&&T->right->data<0) is=false;
		if(T->left&&T->left->data<0) is=false;
	}
	if(!is) return -1;
	int cntl=DFS(T->left);
	int cntr=DFS(T->right);
	if(cntl!=cntr) is=false;
	if(!is) return -1;
	if(T->data>0) return cntl+1;
	else return cntl;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		int k;
		cin>>k;
		BST T=NULL;
		while(k--){
			int x;
			cin>>x;
			T=insert(T,x);
		}
		is=true;
		if(T->data<0) is=false;
		else DFS(T);
		if(!is) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
