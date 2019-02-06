#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
typedef struct node{
	int data;
	node *left,*right;
	node(){
		left=right=NULL;
	}
}*tree;
unordered_map<int,int>mp;
vector<int>pre,in;
tree reconstruct(int prestart,int preend,int instart,int inend){
	tree T=new node;
	T->data=pre[prestart];
	int inroot;
	for(inroot=instart;in[inroot]!=pre[prestart];inroot++);
	if(inroot!=instart){
		int inleftstart=instart,inleftend=inroot-1,preleftstart=prestart+1,preleftend=preleftstart-inleftstart+inleftend;
		T->left=reconstruct(preleftstart,preleftend,inleftstart,inleftend);
		mp[T->left->data]=T->data;
	}
	if(inroot!=inend){
		int inrightstart=inroot+1,inrightend=inend,prerightend=preend,prerightstart=prerightend-inrightend+inrightstart;
		T->right=reconstruct(prerightstart,prerightend,inrightstart,inrightend);
		mp[T->right->data]=T->data;
	}
	return T;
}
int main(){
	int n,m;
	cin>>n>>m;
	pre.resize(m);
	in.resize(m);
	unordered_map<int,bool>isfound;
	for(int i=0;i<m;i++){
		cin>>in[i];
		isfound[in[i]]=true;
	}
	for(int i=0;i<m;i++) cin>>pre[i];
	tree T=reconstruct(0,m-1,0,m-1);
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		if(!isfound[x]&&!isfound[y]) cout<<"ERROR: "<<x<<" and "<<y<<" are not found."<<endl;
		else if(!isfound[x]) cout<<"ERROR: "<<x<<" is not found."<<endl;
		else if(!isfound[y]) cout<<"ERROR: "<<y<<" is not found."<<endl;
		else{
			int lca;
			vector<int>xr,yr;
			for(int a=x;a!=T->data;a=mp[a]) xr.push_back(a);
			xr.push_back(T->data);
			for(int a=y;a!=T->data;a=mp[a]) yr.push_back(a);
			yr.push_back(T->data);
			int b=xr.size()<yr.size()?yr.size()-xr.size():xr.size()-yr.size();
			if(xr.size()<yr.size()) for(int i=0;i<xr.size();i++){
				if(xr[i]==yr[b+i]){
					lca=xr[i];
					break;
				}
			}
			else for(int i=0;i<yr.size();i++){
				if(yr[i]==xr[b+i]){
					lca=yr[i];
					break;
				}
			}
			if(lca==x) cout<<x<<" is an ancestor of "<<y<<'.'<<endl;
			else if(lca==y) cout<<y<<" is an ancestor of "<<x<<'.'<<endl;
			else cout<<"LCA of "<<x<<" and "<<y<<" is "<<lca<<'.'<<endl;
		}
	}
	return 0;
}
