#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct node{
	int left,right;
	string data;
};
vector<node>T;
int root;
void in(int x){
	if(x!=root&&(T[x].left!=-1||T[x].right!=-1)) cout<<'(';
	if(T[x].left!=-1) in(T[x].left);
	cout<<T[x].data;
	if(T[x].right!=-1) in(T[x].right);
	if(x!=root&&(T[x].left!=-1||T[x].right!=-1)) cout<<')';
}
int main(){
	int n;
	cin>>n;
	T.resize(n+1);
	vector<bool>isroot(n+1,true);
	for(int i=1;i<=n;i++){
		cin>>T[i].data>>T[i].left>>T[i].right;
		if(T[i].left!=-1) isroot[T[i].left]=false;
		if(T[i].right!=-1) isroot[T[i].right]=false;
	}
	for(root=1;!isroot[root];root++);
	in(root);
	return 0;
}
